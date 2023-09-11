unsigned long peak(unsigned long nel, int (*less)(unsigned long i, unsigned long j)){
    if (nel==0){
        return 0;
    }
    if (nel==1){
        return 0;
    }
    for (unsigned long k=1; k<nel-1; k++){
        if  ((less(k, k+1)==0)&&(less(k,k-1)==0)){
            return k;
        }
    }
}
