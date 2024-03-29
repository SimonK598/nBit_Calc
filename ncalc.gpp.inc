function convhex2String(result2Conv){
    result = <>;
    idx = sizeof(result2Conv) - 1;
    // echo "passed result2conv is: " # form("%d", result2Conv) # endl;
    while (idx >= 0){
        // echo "current idx: " # form("%d", idx) # endl;
        // echo "--------------------------------------" # endl;
        // echo "byte in result2conv: " # form ("%C", result2Conv[idx]);
        // echo "--------------------------------------" # endl;
        switch (result2Conv[idx]) with |==|{
            case <30>:
                result = "0" # result;
                // echo "test conv: " # form("%s", result) # endl;
                break;
            case <31>:
                result = "1" # result;
                // echo "test conv: " # form("%s", result) # endl;
                break;
            case <32>:
                result = "2" # result;
                // echo "test conv: " # form("%s", result) # endl;
                break;
            case <33>:
                result = "3" # result;
                // echo "test conv: " # form("%s", result) # endl;
                break;
            case <34>:
                result = "4" # result;
                // echo "test conv: " # form("%s", result) # endl;
                break;
            case <35>:
                result = "5" # result;
                // echo "test conv: " # form("%s", result) # endl;
                break;
            case <36>:
                result = "6" # result;
                // echo "test conv: " # form("%s", result) # endl;
                break;
            case <37>:
                result = "7" # result;
                // echo "test conv: " # form("%s", result) # endl;
                break;
            case <38>:
                result = "8" # result;
                // echo "test conv: " # form("%s", result) # endl;
                break;
            case <39>:
                result = "9" # result;
                // echo "test conv: " # form("%s", result) # endl;
                break;
            default:
                echo "error at index: " # idx # endl;
                echo "[converthex2String]--> found this: " # form("%C", result2Conv[idx]) # endl;
        }
        idx = idx - 1;
    }
    // echo "test conv: " # form("%C", result) # endl;
    // echo "test conv: " # this.result # endl;
    return result;
}

function convert2String(result2Conv){
    
    // echo "result2conv:: " # form("%C",result2Conv) # endl;
    result = <>;
    idx = sizeof(result2Conv) - 1;
    // echo "passed result2conv is: " # form("%d", result2Conv) # endl;
    while (idx >= 0){
        // echo "current idx: " # form("%d", idx) # endl;
        // echo "--------------------------------------" # endl;
        // echo "byte in result2conv: " # form ("%C", result2Conv[idx]) # endl;
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
                // echo "error at index: " # idx # endl;
                // echo "[convert2String]--> found this: " # form("%C", result2Conv[idx]) # endl;
                // echo "\n";
                a = 0;
        }
        idx = idx - 1;
    }
    // echo "test conv: " # form("%C", result) # endl;
    // echo "test conv: " # this.result # endl;
    return result;
}

function max(lenA, lenB){
    if (lenA > lenB){
        // A > B -> 1
        return 1;
    }else{
        if (lenA < lenB){
            // A < B -> -1
            return -1;
        }else{
            // A == B -> 0
            return 0;
        }
    }
}

procedure removeP0(str){
    runLoop = TRUE;
    strlen = sizeof(str);
    idx = 0;
    while(runLoop){
        // echo "this.result[" # form("%d", idx) # "]: " # this.result[idx] # endl;
        switch (str[idx]) {
            case ("0"):
                idx++;
                break;
            case (","):
                runLoop = FALSE;
                str = "0" # str[idx..$];
                break;
            default:
                runLoop = FALSE;
                str = str[idx..$];
                break;
        }
        if  (idx >= strlen){
            str = "0";
            runLoop = FALSE;
        }
    }
}

function maxi(nr1, nr2){

    removeP0(&nr1);
    removeP0(&nr2);
    // echo "hex n1:" # form("%C", nr1) # endl;
    // echo "hex n2:" # form("%C", nr2) # endl;
    
    // echo "find max between: " # nr1 # ", and: " # nr2 # endl;
    nr1Len = sizeof(nr1);
    // echo "n1len: " # form("%d", nr1Len) # endl;
    nr2Len = sizeof(nr2);
    // echo "n2len: " # form("%d", nr2Len) # endl;

    switch (max(nr1Len, nr2Len)){
        case (1):
            // echo "swreturn 1\n";
            return 1;
        case (-1):
            // echo "swreturn -1\n";
            return -1;
        case (0):
            if (nr1 |==| nr2){
                // nr1 is equal to nr2
                return 0;
            }
            break;
    }

    // nr1 and nr2 are NOT equal -> go bytewise till one or the other is bigger
    idx = 0;
    while (idx < nr1Len){
        // echo "idx: " # form("%d",idx) # endl;
        // echo "nr1[idx]: " # convert2String(nr1[idx]) # endl;
        // echo "nr2[idx]: " # convert2String(nr2[idx]) # endl;
        num1 = scan("%d",nr1[idx]);
        // echo "nr1[idx]: " # form("%d",scan("%d",nr1[idx])) # endl;
        num2 = scan("%d",nr2[idx]);
        // echo "nr2[idx]: " # form("%d",scan("%d",nr2[idx])) # endl;
        // num3 = num1 + num2;
        // echo "debug num3: " # form("%d", num3) # endl;
        if (num1 > num2){
            // echo "nr1: " # form("%d", num1) # " is bigger than nr2: " # form("%d", num2) # endl;
            // echo "returning 1\n";
            return 1;
        }else{
            if(num1 == num2){
                // vals at idx are same -> continue;
                idx++;
            }else{
                // nr2 is bigger -> return -1
                // echo "returning -1\n";
                return -1;
            }
            // nr2 is bigger 
            // (to be here both numbers need to be the same length so checking for index is not required)
        
            // if (idx < nr1Len-1){
            //     echo "-1" # endl;
            //     return -1;
            // }
        
            // echo "-1" # endl;
            // return -1;
        }
    }
    // echo "1\n" # endl;
    return 1;
}


function maxInt(a, b){
    if (a == b){
        return 0;
    }else{
        if(a > b){
            return 1;
        }else{
            return -1;
        }
    }
}

function solFinder (sols, above){
    found = FALSE;
    idx = 4;
    maxAB = maxi(&above, &sols.(idx));
    carry = 0;
    // echo "|>>> entering sol finder loop...\n";
    while (!found){
        switch (maxAB){
            // above is greater than sol
            case (1):
                // echo "|     switch(maxAB) -> (1)\n";
                switch (carry){
                    // carry was 1 -> keep going up
                    case (1):
                        // echo "|          switch(carry) -> (1)\n";
                        if (idx+1 == 10){
                            found = TRUE;
                            break;
                        }
                        idx++;
                        carry = 1;
                        maxAB = maxi(&above, &sols.(idx));
                        break;
                    // first run; above is greater so -> go up 
                    case (0):
                        // echo "|          switch(carry) -> (0)\n";
                        if (idx+1 == 10){
                            found = TRUE;
                            break;
                        }
                        idx++;
                        carry = 1;
                        maxAB = maxi(&above, &sols.(idx));
                        break;
                    // carry was -1 -> previous sol was bigger than above -> curIdx is highest
                    case (-1):
                        // echo "|          switch(carry) -> (-1)\n";
                        found = TRUE;
                        break;
                }
                break;
            // above is equal to sol -> found sol
            case (0):
                // echo "|     switch(maxAB) -> (0)\n";
                found = TRUE;
                break;
            // above is less than sol -> go down
            case (-1):
                // echo "|     switch(maxAB) -> (-1)\n";
                switch (carry){
                    // carry is 1 -> previous sol was less -> carry is highest
                    case (1):
                        // echo "|          switch(carry) -> (1)\n";
                        idx--;
                        found = TRUE;
                        break;
                    // first run; above is less so -> go down
                    case (0):
                        // echo "|          switch(carry) -> (0)\n";
                        idx--;
                        carry = -1;
                        maxAB = maxi(&above, &sols.(idx));
                        break;
                    // carry was -1 -> previous sol was greater -> go down 
                    case (-1):
                        // echo "|          switch(carry) -> (-1)\n";
                        idx--;
                        carry = -1;
                        maxAB = maxi(&above, &sols.(idx));
                        break;
                }
                break;
        }
    }
    return idx;
}