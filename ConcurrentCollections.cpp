#include "ConcurrentCollections.hpp"

ConcurrentDictionary::ConcurrentDictionary()
{
    std::cpit << "Hello..." ;


}

ConcurrentDictionary::~ConcurrentDictionary<TKey,TValue>()
{

}

int ConcurrentDictionary::Count()
{
    return 0 ;
}

template<class TKey, class TValue>
bool ConcurrentDictionary::TryAdd(TKey, TValue&)
{
    return false ;
}

template<class TKey, class TValue>
bool ConcurrentDictionary::TryRemove(TKey, TValue&)
{
    return false ;
}

template<class TKey, class TValue>
bool ConcurrentDictionary::TryRemove(TKey)
{
    return false ;
}

template<class TKey, class TValue>
bool ConcurrentDictionary::TryGet(TKey, TValue&)
{
    return false ;
}

template<class TKey, class TValue>
bool ConcurrentDictionary::AddOrUpdate(TKey, TValue&)
{
    return false ;
}
