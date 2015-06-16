//
//  main.c
//  Fibinocci-part1
//
//  Created by Arsalan Vakili on 2015-06-10.
//  Copyright (c) 2015 Arsalan Vakili. All rights reserved.
//

#include <stdio.h>

int recursivevalueFibinochi(int remainingstep, int previousvalue, int previouspreviousvalue);
int recursiverefrenceFibinochi(int remainingstep, int *previousvalue, int *previouspreviousvalue);
int Fibinocci(int n);
//
int main(int argc, const char * argv[]) {
    
    int answer= Fibinocci(10);
    printf("the value of result is %d\n",answer);
    
    
    int answer2 = recursivevalueFibinochi(10, 0, 1);
    printf("the value of result2 is %d\n",answer2);
    
    int previousvalue= 0;
    int previouspreviousvalue= 1;
    
    int answer3 = recursiverefrenceFibinochi(10, &previousvalue, &previouspreviousvalue);
    printf("the value for result 3 is %d\n",answer3);
    return 0;
}

int Fibinocci(int n){
    if (n <= 0){
        return 0;
    }

    int result= 0;
    int previousresult= 0;
    int doublepreviousresult= 1;
    
    for (int fibnum = 0; fibnum < n; fibnum++){
        printf("test %i\n", result);
        result = previousresult + doublepreviousresult;
        doublepreviousresult = previousresult;
         previousresult = result;
    }
    return  result;
}

// the second part of the question
int recursivevalueFibinochi(int remainingstep, int previousvalue, int previouspreviousvalue){
    if (remainingstep < 1){
        return  previousvalue;
    }
    else
       return recursivevalueFibinochi(remainingstep -1,previousvalue + previouspreviousvalue,previousvalue);
}


// the third part of the question
int recursiverefrenceFibinochi(int remainingstep, int *previousvalue, int *previouspreviousvalue){
    
    if (remainingstep < 1){
        return  *previousvalue;
    }
    
    int swap = *previousvalue + *previouspreviousvalue ;
    *previouspreviousvalue = *previousvalue ;
    *previousvalue = swap;
    
    
    return recursiverefrenceFibinochi(remainingstep -1,previousvalue,previouspreviousvalue);
}

