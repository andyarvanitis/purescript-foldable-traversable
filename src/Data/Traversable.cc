#include "Traversable.hh"

namespace Data_Traversable {

  using namespace PureScript;

  static auto consList(const any& x) -> any {
    return [=](const any& xs) -> any {
      return any::map {
        { KEY("head"), x },
        { KEY("tail"), xs }
      };
    };
  }

  static auto listToArray(const any& list_) -> any {
    any::vector arr;
    any list = list_.cast<any::map>();
    while (not list.cast<any::map>().empty()) {
      arr.push_back(list[KEY("head")]);
      list = list[KEY("tail")];
    }
    return arr;
  }

  static auto emptyList() -> any {
    return any::map();
  }

  static auto go(const any& acc,
                 const size_t currentLen,
                 const any::vector& xs,
                 const any& buildFrom) -> any::map {

    if (currentLen == 0) {
      return any::map{ { KEY("acc"), acc } };
    } else {
      const auto last = xs[currentLen - 1];
      const auto fn = [=, &xs]() -> any {
        return go(buildFrom(last)(acc), currentLen - 1, xs, buildFrom);
      };
      return any::map{ { KEY("fn"), fn } };
    }
  };

  auto traverseArrayImpl(const any& apply) -> any {
    return [=](const any& map) -> any {
      return [=](const any& pure) -> any {
        return [=](const any& f) -> any {
          const auto buildFrom = [=](const any& x) -> any {
            return [=](const any& ys) -> any {
              return apply(map(consList)(f(x)))(ys);
            };
          };
          return [=](const any& array_) -> any {
            const auto& array = array_.cast<any::vector>();
            any result = go(pure(emptyList()), array.size(), array, buildFrom);
            while (result.cast<any::map>().count(KEY("fn")) > 0) {
              any fn = result[KEY("fn")];
              result = fn();
            }
            return map(listToArray)(result[KEY("acc")]);
          };
        };
      };
    };
  }

} // namespace Data_Traversable
