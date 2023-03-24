#include "D:\Ubb\SDD\TAD-COLECTIE\header\Colectie_Sem.h"


Collection::Collection() {

    this -> capacity = 10;
    this -> elements = new TElem [capacity];
    this -> occurrences = new int [capacity];
    this -> distinctelements = 0;

}

void Collection::destroy()
{
    delete[] this-> occurrences;
    delete[] this->elements;
    this->distinctelements =0;

}

void Collection::add(TElem e)
{
    if(distinctelements == capacity)
        resize();
    int poz=-1;

    if (!search(e))
    {
        for (int i = 0; i < this-> distinctelements ; i++)
            if (this->elements[i] > e)
                poz = i;

        for (int j = this ->distinctelements ; j >poz ;j--)
            this-> elements[j] = this->elements[j-1];
        this -> elements[poz] =e;
        this ->distinctelements++;

    }


}


bool Collection::search(TElem elem) {
    for(int i = 0; i < this ->distinctelements; i++)
        if (this-> elements[i] == elem)
            return true;
    return false;
}



int Collection::size()
{
    return this ->capacity;


}

int  Collection :: nroccurrences(TElem elem)
{
    if(search(elem))
    {
        int poz =-1;
        for (int i = 0; i < this-> distinctelements ; i++)
            if (this->elements[i] == elem)
                poz = i;
        return this->occurrences[poz];
    }
    else
    return 0;

}

void Collection::resize()
{
    TElem * newElems = new TElem [this->capacity*2];

    for(int i =0; i < this-> distinctelements;i++)
        newElems[i] = this->elements[i];
    capacity*=2;

    delete[] this ->elements;

    this -> elements = newElems;

    int * newFr = new int[this->capacity];

    for(int i =0; i < this-> distinctelements;i++)
        newFr[i] = this->occurrences[i];
    delete[] this -> occurrences;

    this -> occurrences = newFr;


}

bool Collection::remove(TElem elem)
{
    if(search(elem))
    {
        int poz =-1;
        for (int i = 0; i < this-> distinctelements ; i++)
            if (this->elements[i] == elem)
                poz = i;

        for (int i = poz; i <this->distinctelements; i++)
        {
            this->elements[i] = this->elements[i + 1];
            this ->occurrences[i] = this->occurrences[i+1];
        }
        this -> distinctelements -- ;
        return true;


    }
    return false;


}


int Collection::getAt(int position)
{
    if(position>=0 && position < this->distinctelements)
        return this->elements[position];
    return -1;


}