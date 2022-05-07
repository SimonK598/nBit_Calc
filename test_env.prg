include("std.inc");
include ("conv.inc");
include ("./ncalc.gpp.inc");
include ("./ncalc.def.inc");
include ("./ncalc.fnc.inc");

function convert2String(result2Conv){
    result = <>;
    idx = sizeof(result2Conv) - 1;
    // echo "passed result2conv is: " # form("%C", result2Conv) # endl;
    while (idx >= 0){
        // echo "current idx: " # form("%d", idx) # endl;
        // echo "--------------------------------------" # endl;
        // echo "byte in result2conv: " # form ("%C", result2Conv[idx]);
        // echo "--------------------------------------" # endl;
        switch (result2Conv[idx]) with |==|{
            case <00>:
                result = "0" # result;
                // echo "test conv: " # form("%s", result) # endl;
                break;
            case <01>:
                result = "1" # result;
                // echo "test conv: " # form("%s", result) # endl;
                break;
            case <02>:
                result = "2" # result;
                // echo "test conv: " # form("%s", result) # endl;
                break;
            case <03>:
                result = "3" # result;
                // echo "test conv: " # form("%s", result) # endl;
                break;
            case <04>:
                result = "4" # result;
                // echo "test conv: " # form("%s", result) # endl;
                break;
            case <05>:
                result = "5" # result;
                // echo "test conv: " # form("%s", result) # endl;
                break;
            case <06>:
                result = "6" # result;
                // echo "test conv: " # form("%s", result) # endl;
                break;
            case <07>:
                result = "7" # result;
                // echo "test conv: " # form("%s", result) # endl;
                break;
            case <08>:
                result = "8" # result;
                // echo "test conv: " # form("%s", result) # endl;
                break;
            case <09>:
                result = "9" # result;
                // echo "test conv: " # form("%s", result) # endl;
                break;
            default:
                echo "error at index: " # idx # endl;
                echo "--> found this: " # form("%C", result2Conv[idx]) # endl;
        }
        idx = idx - 1;
    }
    // echo "test conv: " # form("%C", result) # endl;
    echo "test conv: " # result # endl;
    return result;
}

function maxi(nr1, nr2){
    if (nr1 |==| nr2){
        // nr1 is equal to nr2
        return 0;
    }
    // nr1 and nr2 are NOT equal -> go bytewise till one or the other is bigger
    nr1Len = sizeof(nr1);
    nr2Len = sizeof(nr2);
    idx = 0;
    while (idx < nr1Len){
        echo "nr1[idx]: " # convert2String(nr1[idx]) # endl;
        echo "nr2[idx]: " # convert2String(nr2[idx]) # endl;
        if (scan("%d",convert2String(nr1[idx])) >= scan("%d",convert2String(nr2[idx]))){
            idx++;
        }else{
            if (idx < nr1Len-1){
                // nr2 is bigger 
                echo "-1" # endl;
                return -1;
            }
        }
    }
    echo "1\n" # endl;
    return 1;
}

procedure main(){
    /* 
    stri = "01234,56789";
    nr1decCount = -1;
    nr1decPos = -1;
    nr1dec = FALSE;
    idx1 = 0;
    while(idx1 < sizeof (stri)){
        if (stri[idx1] == ","){
            nr1dec = TRUE;
            nr1decPos = idx1;
        }
        if(nr1dec == TRUE){
            nr1decCount++;
        }
        idx1++;
    }
    stri = stri[0..(nr1decPos-1)] # stri[(nr1decPos+1)..$];
    echo stri # endl */;


    // sol = sub(12,0);
    // echo "sol: " # form("%C",sol) # endl;

    // strg = "12";
    // strgS = <>;
    // strgS = strg # strgS;
    // echo "custom: " # form("%C", strgS);

    // nr1 = <>;
    // nr2 = <>;
    // echo "haha\n";
    // idx = 1;
    // while (idx < 4){
    //     nr1 = idx # nr1;
    //     nr2 = idx + 2 # nr2;
    //     idx++;
    // }
    // echo "calling maxi...\n";
    // echo "maxi result for nr1 = " # convert2String(nr1) # " and nr2 = " # convert2String(nr2) # " is: " # form("%i",maxi(nr1,nr2)) # endl;

    // result = <>;
    // idx = 0;
    // while (idx < 10){
    //     result = idx # result;
    //     idx = idx + 1;
    // }

    // echo "result of adding bytes to chain: \n" # form("%C", result) # endl;

    // idx = 0;
    // while (idx < sizeof(result)){
    //     echo "debug: result at index is: " # form("%s", result[idx]) # endl;
    //     idx ++;
    // }

    // convert2String(result);^
}