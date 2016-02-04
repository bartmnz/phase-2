#include <stdio.h>
#include <stdbool.h>

/* searches for the string needle in the sorted array of strings arr (of length n)
 *
 */
 
bool str_in_list(const char *needle, const char **arr, size_t n){
    if ( ! arr || ! needle || n == 0){
        return false;
    }
    int pos = n/2;
    rValue = strcmp(needle, arr[pos]);
    if( n == 1 ) return rValue;
    if( ! rValue ) return true;
    
    return ! rValue || rValue < 0 ? 
        str_in_list(needle, arr, pos) : 
        str_in_list(needle, arr[pos]+1, n - pos - 1);
}

int unimodial_get_mode(int *arr, size_t n){
    if (! arr || n == 0){
        return 0;
    }
    if ( n > 2){
        int half = n/2;
        bool left_increasing = arr[0] < arr[1];
        bool right_increasing = array[half] < array[half-1];
        if ( left_increasing && right_increasing ){
            return unimodial_get_mode(array[half], n - half);
        } else if ( left_increasing && !right_increasing){
            return unimodial_get_mode(array, half);
        } else {
            int right_max = unimodial_get_mode(array[half], n - half);
            return array[0] > right_max ? array[0] : right_max;
        }
    }
    if (n == 2) {
        return arr[0] > arr[1] ? arr[0] : arr[1];
    }
    return arr[0];
}

int find_first(char * needle, char * arr[], size_t n){
    if (! arr || n == 0){
        return 0;
    }
    if ( n > 2){
        int half = n/2;
        int isHalf = strcmp(needle, arr[half]);
        // didn't found it -- could be later
        if ( isHalf > 0) ){
            int rValue = find_first( needle, &arr[half], n-half);
            return rValue < 0 ? rValue : half + rValue;
        } // found it could still be earlier
        else if (! isHalf) {
            int rValue = find_first( needle, arr, half);
            return rValue < 0 ? half : rValue;
        } // didn't find it check the first half
        else{
            return find_first( needle, arr, half);
        }
    } else {
        int index;
        if ( strcmp(needle, arr[0])) return 0;
        else if ( strcmp(needle, arr[n-1])) return n-1;
        else return -1;
    }
}