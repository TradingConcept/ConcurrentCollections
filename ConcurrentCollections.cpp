#include "ConcurrentCollections.hpp"

namespace Collections
{

template <typename TKey, typename TValue>
ConcurrentDictionary<TKey, TValue>::ConcurrentDictionary()
{
    std::cout << "ConcurrentDictionary Constructor Called" << std::endl;
}

template <typename TKey, typename TValue>
bool ConcurrentDictionary<TKey, TValue>::PrintDictionary()
{
    std::cout << "Hellyeah!\n";
    return true;
}

template <typename TKey, typename TValue>
long const ConcurrentDictionary<TKey, TValue>::size()
{
    std::lock_guard m(this->mutex);
    return std::map<TKey, TValue>::size();
}

template <typename TKey, typename TValue>
TValue &ConcurrentDictionary<TKey, TValue>::operator[](const TKey &key)
{
    std::lock_guard m(this->mutex);
    return std::map<TKey, TValue>::operator[](key);
}

template <typename TKey, typename TValue>
TValue &ConcurrentDictionary<TKey, TValue>::operator[](TKey &&key)
{
    std::lock_guard m(this->mutex);
    return std::map<TKey, TValue>::operator[](key);
}

template <typename TKey, typename TValue>
bool ConcurrentDictionary<TKey, TValue>::TryAdd(TKey k, const TValue &v)
{
    auto p = std::pair<TKey, TValue>(k, v);
    std::lock_guard m(this->mutex);
    return this->insert(p).second;
}

template <typename TKey, typename TValue>
bool ConcurrentDictionary<TKey, TValue>::TryRemove(TKey k, TValue &v)
{
    std::lock_guard m(this->mutex);
    auto it = this->find(k);
    if (it != this->end())
    {
        v = it->second;
        this->erase(it);
        return true;
    }   
    return false;
}

template <typename TKey, typename TValue>
bool ConcurrentDictionary<TKey, TValue>::TryRemove(TKey k)
{
    std::lock_guard m(this->mutex);
    auto it = this->find(k);
    if (it != this->end())
    {
        this->erase(it);
    }

    return false;
}

template <typename TKey, typename TValue>
bool ConcurrentDictionary<TKey, TValue>::TryGet(TKey k, TValue &v)
{
    std::lock_guard m(this->mutex);
    auto it = this->find(k);
    if (it != this->end())
    {
        v = it->second;
    }

    return false;
}

template <typename TKey, typename TValue>
bool ConcurrentDictionary<TKey, TValue>::AddOrUpdate(TKey, TValue &)
{
    std::lock_guard m(this->mutex);
    return false;
}

} // namespace Collections
