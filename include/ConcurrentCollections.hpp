#ifndef CONCURRENTCOLLECTIONS_HPP_INCLUDED
#define CONCURRENTCOLLECTIONS_HPP_INCLUDED

#include <iostream>
#include <map>
#include <mutex>
#include <thread>

namespace Collections
{

template <typename TKey, typename TValue>
class ConcurrentDictionary : public std::map<TKey, TValue>
{
    std::mutex mutex ;

public:
    ConcurrentDictionary();
    // ~ConcurrentDictionary();

    bool PrintDictionary();
    long const size();

    TValue &operator[](const TKey &key);
    TValue &operator[](TKey &&key);

    bool TryAdd(TKey, const TValue &);
    bool TryRemove(TKey, TValue &);
    bool TryRemove(TKey);
    bool TryGet(TKey, TValue &);
    bool AddOrUpdate(TKey, TValue &);
};

// NOTA: EN C++ los templates se definen en tiempo de compilación, por lo que no pueden existir "clases templeteadas" salvo que las pre-indiquemos (cosa poco flexible, pero fácil de resolver)
template class ConcurrentDictionary<int, int>;
template class ConcurrentDictionary<int, std::string>;
template class ConcurrentDictionary<std::string, int>;

}; // namespace Collections

#endif // CONCURRENTCOLLECTIONS_HPP_INCLUDED
