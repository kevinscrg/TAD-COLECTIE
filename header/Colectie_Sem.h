#pragma once


typedef int TElem;
class Collection {
private:
    TElem* elements;
    int* occurrences;
    int distinctelements; //nr de elem distincte (lungimea lu elements)
    int capacity;
    void resize();
public:
    Collection();
    void add(TElem elem);
    bool remove(TElem elem);
    bool search(TElem elem);
    int size() ;
    int nroccurrences(TElem elem);
    void destroy();
    /**
    * this will be removed
    */
    int getAt(int position);
};

