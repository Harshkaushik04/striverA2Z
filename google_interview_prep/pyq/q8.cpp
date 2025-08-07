#include<bits/stdc++.h>
using namespace std;

/*
You’ll be given a stream of numbers, at every input tell whether there exists a triplet such that the pairwise difference of all the 3 elements of the triplet is atmost d.
*/

/*
first  we will find the length of queries if length is less than or equal to 2 then we would return
empty vector
will use a set to store incoming numbers for example queries is:
{1,5,32,1,4,52,24,4,21}, d=20
{1,5}
apply for loop on queries from 2 to n
  find upper and lower bound of the "number to be inserted" inside set

  { , , x1,x,|||||,y,y1 , , , }
   for triplet including the number we are inserting then possible pairs can only be
   1.{x1,x,|||||}  2.{x,||||||,y}  3.{||||||,y,y1} 
    lets suppose we found upper bound first, we would check if upper bound==set.end() 
    if its equal to set.end() it means upper bound doesnt exists=>therefore the number to be 
    inserted is lowest in set
    similarly if lower bound doesnt exists=>number to be inserted is highest in set
    if upper bound exists then we need to check whether upper bound-1 is inside array or not , 
    similarly for lower bound
    then for any one of the statements to be right we need to ensure that 
    (in general form) mod(extreme1 -extreme2)<=d

*/

// {1,5,32,1,4,52,24,4,21} d=20
vector<string> whetherExistsTriplet(vector<int>& queries,int d){
    int length=queries.size();
    if(length<=2) return vector<string>();
    multiset<int> numbers={queries[0],queries[1]};
    vector<string> answerArr;
    for(int index=2;index<length;index++){ //iterating over the queries
        multiset<int>::iterator lowerBound=numbers.lower_bound(queries[index]);
        multiset<int>::iterator upperBound=numbers.upper_bound(queries[index]);
        if(upperBound==numbers.end()){ //queries[index] will be lowest element in multiset, so only 3rd conditin is possible
            int y=(*numbers.begin());
            int y1=(*(numbers.begin()+1));
            if(y1-queries[index]<=d) answerArr.emplace_back("YES");
            else answerArr.emplace_back("NO");
        }
        else if(lowerBound==numbers.end()){ //queries[index] will be highest and only 1st condition is possible
            int x=*numbers.end();
            int x1=*(numbers.end()-1);
            if(queries[index]-x1<=d) answerArr.emplace_back("YES");
            else answerArr.emplace_back("NO");
        }
        else{
            if(lowerBound+1==numbers.end()){ //then 3rd case doesnt exists
                

            }
            if(upperBound-1==number.begin()){ //then 1st case doesnt exists

            }
            else{

            }
        }
    }
}