void selectionsort_by_firstname(struct Student a[],int n) {

        int pos;
        struct Student gem;

        for(int i=0; i<n-1; i++) {

            pos=i;

            //finding lowest index
            for(int j=i+1;j<n;j++){

                if(0 < strcmp(a[pos].firstname, a[j].firstname)){
                    pos=j;
                }

            }

            //swapping indexes
            if(pos!=i){

                struct Student tmp = a[i];
                a[i] = a[pos];
                a[pos] = tmp;

            }
        }
}

void selectionsort_by_avrgrade(struct Student a[],int n) {

        int pos;
        struct Student gem;

        for(int i=0; i<n-1; i++) {

            pos=i;

            //finding lowest index
            for(int j=i+1;j<n;j++){

                if(a[pos].avr_grade > a[j].avr_grade){
                    pos=j;
                }

            }

            //swapping indexes
            if(pos!=i){

                struct Student tmp = a[i];
                a[i] = a[pos];
                a[pos] = tmp;

            }
        }
}