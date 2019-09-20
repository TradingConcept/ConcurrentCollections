#ifndef CONCURRENTCOLLECTIONS_HPP_INCLUDED
#define CONCURRENTCOLLECTIONS_HPP_INCLUDED

#include <iostream>
#include <map>

namespace Collections {

    template<class TKey, class TValue>
    class ConcurrentDictionary : std::map<TKey,TValue> {

    public:
        ConcurrentDictionary();
        ~ConcurrentDictionary();

        int Count();

        // TKey[] Keys ;
        // TValue[] Values ;

        bool TryAdd(TKey, TValue&);
        bool TryRemove(TKey, TValue&);
        bool TryRemove(TKey);
        bool TryGet(TKey, TValue&);
        bool AddOrUpdate(TKey, TValue&);

    };

};



#endif // CONCURRENTCOLLECTIONS_HPP_INCLUDED
