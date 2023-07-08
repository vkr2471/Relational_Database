
//This file contains the implementation of natural join
/**********************************************************************************************/
#include"rdb.h"
#include<iostream>
using namespace std;

Relation *naturaljoin(Relation *R1, Relation *R2, list<string> joinattr)
{
    
    int i = 0, j = 0;
    DNFformula dnf;
    vector<string> R2uniq;//vecotr to store the attributes of R2 which are not in joinattr
    list<string> R1R2;//list to store the attributes of R1 and R2
    auto it1 = joinattr.end();//it1 to poin to the last element of joinattr
    auto it = joinattr.begin();
    if(it1!=it)it1--;
    for (i = 0; i < R2->nattr; i++)//fiding the unique attributes of R2
    {
        if ((joinattr.size()!=0)&&((*it) != R2->attrnames[i]))//checking if the attribute is not in joinattr
            R2uniq.push_back(R2->attrnames[i]);
        else if(joinattr.size()==0)//size is zero case.. dealt seperately to avoid segmentation fault
            R2uniq.push_back(R2->attrnames[i]);
        else if(it != it1)it++;
          
    }
    //finding the attribute names is R1 and R2
    for (int i = 0; i < R1->nattr; i++)
    {
        R1R2.push_back(R1->attrnames[i]);
    }
    for (auto it = R2uniq.begin(); it != R2uniq.end(); it++)
    {
        R1R2.push_back(*it);
    }
   
    char b[][4] = {"r", "s", "t", "u", "v", "w", "x", "y", "r9", "r10"};// array to store the names which are used to remane the attributes of R2
    vector<int> i1;// to store the indices of the attributes of R1 which are in joinattr
    vector<int> i2;//to store the indices of the attributes of R2 which are in joinattr
    for (i = 0; i < R1->nattr; i++)//finding the indices of the attributes of R1 which are in joinattr
    {
        for (auto it = joinattr.begin(); it != joinattr.end(); it++)
        {
            if (R1->attrnames[i] == *(it))
            {
                i1.push_back(i);
                break;
            }
        }
    }

    for (i = 0; i < R2->nattr; i++)//finding the indices of the attributes of R2 which are in joinattr
    {
        for (auto it = joinattr.begin(); it != joinattr.end(); it++)
        {
            if (R2->attrnames[i] == *(it))
            {
                i2.push_back(i);
                break;
            }
        }
    }
  
   
    i = 0;
    Relation* R3 = new Relation;//creating a new relation r3 as duplicate of R2 to preserve r2 while renaming the attributes
    R3->nattr=R2->nattr;
    R3->nrecs=R2->nrecs;

    for(int i=0;i<R2->nattr;i++)//copying the attributes names  of R2 to R3
    {
        R3->attrnames.push_back(R2->attrnames[i]);
    } 
    for(auto it  =R2->recs.begin();it!=R2->recs.end();it++)//copying the records of R2 to R3
    {
        R3->recs.push_back(new Record(**it));
    }
    i=0;
    for (auto it = joinattr.begin(); it != joinattr.end(); it++)//renaming the attributes of R3 which are in joinattr
    {
        difference(R3, (*it), b[i]);
        i++;
    }
    Relation *cartprod = catersianproduct(R1, R3);//finding the cartesian product of R1 and R3
    for (auto it = cartprod->recs.begin(); it != cartprod->recs.end(); it++)//making dnf fromula such that the commmon attributes have same value
    {
        list<tuple<string, char, Attr *>> a;
        for (int i = 0; i != i1.size(); i++)
        {
           
           //adding two tuples such that they belong to the same record and both are equal
            a.push_back(make_tuple(R1->attrnames[i1[i]], '0', ((*it)->getptr())[(R1->nattr) + i2[i]]));
            a.push_back(make_tuple(b[i], '0', ((*it)->getptr())[(R1->nattr) + i2[i]]));
        }
        dnf.ops.push_back(a);
    } 
    Relation *select = runion(cartprod, &dnf);//selection based the dnf formula
    Relation *ans = projection(select, R1R2);//prjection used to removed the renamed attributes
    delete R3;//deleting the duplicate relation
    return ans;//returning the answer
}
