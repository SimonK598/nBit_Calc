include("std.inc");
include ("conv.inc");
// include ("ascii.inc");
// include ("./convert.inc");

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
                echo "\n";
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

function maxi(nr1, nr2){

    echo "find max between: " # nr1 # ", and : " # nr2 # endl;

    if (nr1 |==| nr2){
        // nr1 is equal to nr2
        return 0;
    }
    // nr1 and nr2 are NOT equal -> go bytewise till one or the other is bigger
    nr1Len = sizeof(nr1);
    nr2Len = sizeof(nr2);
    idx = 0;
    while (idx < nr1Len){
        // echo "idx: " # form("%d",idx) # endl;
        // echo "nr1[idx]: " # convert2String(nr1[idx]) # endl;
        // echo "nr2[idx]: " # convert2String(nr2[idx]) # endl;
        num1 = scan("%d",nr1[idx]);
        echo "nr1[idx]: " # form("%d",scan("%d",nr1[idx])) # endl;
        num2 = scan("%d",nr2[idx]);
        echo "nr2[idx]: " # form("%d",scan("%d",nr2[idx])) # endl;
        num3 = num1 + num2;
        echo "debug num3: " # form("%d", num3) # endl;
        if (num1 > num2){
            echo "nr1: " # form("%d", num1) # " is bigger than nr2: " # form("%d", num2) # endl;
            return 1;
        }else{
            if(num1 == num 2){
                // vals at idx are same -> continue;
                idx++;
            }else{
                // nr2 is bigger -> return -1
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

struct nCalc{
    .nr1;
    .nr2;
    .operator;
    .result;
    .swap;

    function divi ();
    function mult ();
    function subt ();
    function addi ();

    procedure printCalc();

    // function convert2String(result2Conv);

    procedure Create(nr1, nr2, op);
}

// Numbers (nr1/nr2) are literal hex values of chars in String ("0" -> [0x30], "12" -> [0x31,0x32])
procedure nCalc.Create(nr1, nr2, op){
    this.nr1 = nr1;
    // echo "[Create] nr1: " # form("%C", this.nr1) # endl;
    this.nr2 = nr2;
    // echo "[Create] nr2: " # form("%C", this.nr2) # endl;
    this.operator = op;
    this.result = <>;
    this.swap = FALSE;
}

procedure nCalc.printCalc(){
    echo "|-[printCalc]-----------------------|\n";
    echo "this.nr1:         " # this.nr1 # endl;
    echo "this.nr2:         " # this.nr2 # endl;
    echo "this.operator:    " # this.operator # endl;
    echo "this.result:      " # this.result # endl;
    if (this.swap |==| <00>){
        echo "this.swap:        FALSE" # endl;
    }else{
        echo "this.swap:        TRUE" # endl;
    }
    echo "|-----------------------------------|\n";
}

function nCalc.divi(){
    echo "todo\n";
}

function nCalc.mult(){
    echo "todo\n";
}

function nCalc.subt(){
    echo "subt was called...\n";
    this:printCalc();
    
    swap = FALSE;
    
    nr1Len = sizeof(this.nr1)-1;
    nr2Len = sizeof(this.nr2)-1;
    biggerLen = max(nr1Len,nr2Len);
    // echo "stage 1\n";
    if (biggerLen == -1){
        // nr2 is longer (therefore bigger) -> swap nr1 with nr2
        echo "swap bc of biggerLen/max()\n";
        tmpNr1 = this.nr1;
        this.nr1 = this.nr2;
        this.nr2 = tmpNr1;
        ~tmpNr1;
        nr1LenTMP = nr1Len;
        nr1Len = nr2Len;
        nr2Len = nr1LenTMP;
        ~nr1LenTMP;
        this.swap = TRUE;
        swap = TRUE;
    }else{
        if (biggerLen == 0){
            // nr1 and nr2 are same length -> find bigger number
            maxiRet = maxi(this.nr1, this.nr2);
            if(maxiRet == 0){
                // nr1 is equal to nr2 -> result = 0
                this.result = "0";
                return 0;
            }else{
                if (maxiRet == -1){
                    echo "swap bc of biggerVal/maxi()\n";
                    tmpNR1 = this.nr1;
                    this.nr1 = this.nr2;
                    this.nr2 = tmpNR1;
                    nr1Len = sizeof(this.nr1)-1;
                    nr2Len = sizeof(this.nr2)-1;
                    this.swap = TRUE;
                    swap = TRUE;
                }else{
                    swap = FALSE;
                }
            }
        }
    }
    // echo "stage 2\n";
    // carry for next left neighbour
    precarry = 0;
    result = <>;
    // loop1
    while (nr2Len >= 0){

        num1 = scan("%d",this.nr1[nr1Len]);
        // echo "loop1 num1: " # form("%d",num1) # endl;
        num1 = num1 + precarry;
        // echo "loop1 num1 - precarry: " # form("%d",num1) # endl;

        num2 = scan("%d",this.nr2[nr2Len]);
        // echo "loop1 num2: " # form("%d",num2) # endl;

        if (num1 < num2){
            // get 1 from next neighbour until done
            if(num1 == -1){
                num1 = 9;
            }else{
                num1 = num1 + 10;
            }
            precarry = -1;
        }else{
            precarry = 0;
        }

        num3 = num1 - num2;
        // echo "num3: " # form("%d", num3) # endl;
        if(nr2Len == 0 && nr1Len == 0){
            if (num3 != 0){
                result = num3 # result;
            }
        }else{
            result = num3 # result;
        }
        // echo "tmp1 result: " # form("%d", result) # endl;

        nr1Len = nr1Len - 1;
        nr2Len = nr2Len - 1; 
    }

    // echo "stage 3\n";
    while (nr1Len >= 0){
        num1 = scan("%d",this.nr1[nr1Len]);
        // echo "loop2 num1: " # form("%d",num1) # endl;
        
        num1 = num1 + precarry;
        // echo "loop2 num1 - precarry: " # form("%d",num1) # endl;
        
        if(num1 == -1){
            num1 = 9;
            precarry = -1;
        }else{
            precarry = 0;
        }

        // echo "loop2 nr1Len: " # form("%d", nr1Len) # endl;
        if(nr1Len == 0){
            // echo "nr1Len is 0\n";
            // echo "loop2 nr1Len == 0 and num1 = " # form("%d", num1) # endl;
            if (num1 == 0){
                // echo "num1 is zero -> dont prepend to solution\n";
                break;
            }
        }
        result = num1 # result;
        // echo "tmp2 result: " # form("%d", result) # endl;
        
        nr1Len = nr1Len - 1;
    }

    // echo "Sub result before conversion is: " # endl;
    echo form("%C",result) # endl;


    // echo "calling convert2String...\n";
    this.result = convert2String(result);

    if(swap){
        this.result = "-" # this.result;
    }

}

function nCalc.addi(){
    // echo "---------[addi]---------\n";
    carry = 0;
    result = <>;

    nr1Len = sizeof(this.nr1)-1;
    nr2Len = sizeof(this.nr2)-1;
    
    // echo "nr1Len: " # form("%d",nr1Len) # endl;
    // echo "nr2Len: " # form("%d",nr2Len) # endl;

    biggerLen = max(nr1Len, nr2Len);

    if (biggerLen == -1){
        // this:printCalc();
        // nr2 longer than nr1 -> swap this.nr1 and this.nr2 and its according lengths 
        tmpNr1 = this.nr1;
        this.nr1 = this.nr2;
        this.nr2 = tmpNr1;
        ~tmpNr1;
        nr1LenTMP = nr1Len;
        nr1Len = nr2Len;
        nr2Len = nr1LenTMP;
        ~nr1LenTMP;
        // this:printCalc();
    }
    
    // echo "while loop-Nr.: 1\n";
    while (nr2Len >= 0){

        num1 = scan("%d",this.nr1[nr1Len]);
        // echo "num1: " # form("%d",num1) # endl;

        num2 = scan("%d",this.nr2[nr2Len]);
        // echo "num2: " # form("%d",num2) # endl;

        num3 = num1 + num2 + carry;
        // echo "num3: " # form("%d", num3) # endl;

        if (num3 > 9){
            num3 = num3 - 10;
            carry = 1;
        }else{
            carry = 0;
        }

        result = num3 # result;
        // echo "tmp result is: " # form("%C",result) # endl;
        // echo "carry is: " # form("%d",carry) # endl;

        nr1Len = nr1Len - 1;
        // echo "nr1Len: " # form("%d",nr1Len) # endl;

        nr2Len = nr2Len - 1;
        // echo "nr2Len: " # form("%d",nr2Len) # endl;
    }
    
    // echo "while loop-Nr.: 2\n";
    while (nr1Len >= 0){
        num1 = scan("%d",this.nr1[nr1Len]);
        // echo "num1: " # form("%d",num1) # endl;

        num1 = num1 + carry;
        if(num1 > 9){
            num1 = num1 - 10;
            result = num1 # result;
            carry = 1;
            nr1Len = nr1Len - 1;
        }else{
            nr1Len = nr1Len - 1;
            result = num1 # result;
            carry = 0;
        }
    }

    // echo "final tmp result Addi: " # form("%C",result[0..$]) # endl;

    if (carry != 0){
        result = carry # result;
    }
    // echo "calling convert2String...\n";
    this.result = convert2String(result);

    // echo "---------[/addi]--------\n";
}

function splitTerm(term){
    nCalc toCalc;

    strLen = sizeof(term);

    idx = 0;
    while(idx < strLen){
        switch (term[idx]) with |==|
        {
            case "+":
                echo "todo: addition\n";
                echo "nr1: " # term[0..idx-1] # endl;
                echo "nr2: " # term[idx+1..strLen-1] # endl;
                toCalc:Create(term[0..idx-1], term[idx+1..strLen-1], "+");

                // toCalc.nr1 = term[0..idx-1];
                // toCalc.nr2 = term[idx+1..strLen-1];
                // toCalc.operator = "+";
                
                toCalc:addi();
                return toCalc;
                break;
            case "-":
                // echo "todo: subtraction\n";
                echo "nr1: " # term[0..idx-1] # endl;
                echo "nr2: " # term[idx+1..strLen-1] # endl;
                toCalc:Create(term[0..idx-1], term[idx+1..strLen-1], "-");

                // toCalc.nr1 = term[0..idx-1];
                // toCalc.nr2 = term[idx+1..strLen-1];
                // toCalc.operator = "-";
                
                toCalc:subt();
                return toCalc;
                break;
            case "*":
                echo "todo: multiplication\n";
                echo "nr1: " # term[0..idx-1] # endl;
                echo "nr2: " # term[idx+1..strLen-1] # endl;
                toCalc:Create(term[0..idx-1], term[idx+1..strLen-1], "*");
                
                // toCalc.nr1 = term[0..idx-1];
                // toCalc.nr2 = term[idx+1..strLen-1];
                // toCalc.operator = "*";
                
                toCalc:mult();
                return toCalc;
                break;
            case "/":
                echo "todo: division\n";
                echo "nr1: " # term[0..idx-1] # endl;
                echo "nr2: " # term[idx+1..strLen-1] # endl;
                toCalc:Create(term[0..idx-1], term[idx+1..strLen-1], "/");

                // toCalc.nr1 = term[0..idx-1];
                // toCalc.nr2 = term[idx+1..strLen-1];
                // toCalc.operator = "/";
                
                toCalc:divi();
                return toCalc;
                break;
            default:
                // echo "no sign found -> continue...\n";
                idx++;
        }
    }
}

procedure testSub(){
    idx1 = 0;
    idx2 = 0;
    toBreak = FALSE;
    nCalc test;
    while(idx1 < 55){
        while(idx2 < 66){
            echo "idx1: " # form("%d", idx1) # ", idx2: " # form("%d", idx2) # endl;

            sol = idx1 - idx2;
            // echo "sol is: " # form("%d",sol) # endl;
            ~test;
            nCalc test;
            test:Create(form("%d",idx1), form("%d",idx2), "-");
            // test:printCalc();
            test:subt();
            testRes = form("%d",convert2String(test.result));
            // echo "test.result is: " # testRes # endl;
            if(test.result |!=| form("%d",sol)){
                // if (form("%d",test.result) != form("%d",sol)){
                //     echo "Calculation error at:\n";
                //     test:printCalc();
                //     echo "Expected: " # form("%d",sol) # ", but was: " # test.result # endl;
                //     toBreak = TRUE;
                //     break;
                // }
                echo "Calculation error at:\n";
                test:printCalc();
                echo "Expected: " # form("%d",sol) # ", but was: " # test.result # endl;
                toBreak = TRUE;
                break;
            }
            else{
                echo "-----------------------------------------\n";
                echo "calc was correct: " # endl;
                test:printCalc();
                echo "-----------------------------------------\n";
            }
            idx2++;
        }
        if(toBreak){
            break;
        }
        idx2 = 0;
        idx1++;
    }
}

procedure testAdd(){
    startPos = 5;
    idx = 0;
    nCalc testThis;
    while (idx < 111){
        ~testThis;
        nCalc testThis;
        testThis:Create(form("%d",startPos), form("%d",idx), "+");
        testThis:addi();
        // sol = idx + startPos;
        sol = add(5, idx);
        if (testThis.result |==| form("%d", (sol))){
            echo "Wrong result at run: " # form("%d", idx) # endl # "expected: " # form("%d", (sol)) # ", but was: " # this.result # endl;
            break;
        }
        testThis:printCalc();
        idx++;
    }
}

procedure main (){

    // testAdd();
    // testSub();


    term = ARGV.[1];
    echo sizeof(ARGV.[1]);
    nCalc toCalc;
    toCalc = splitTerm(&term);
    echo "----------------------------------------\n";
    // echo "finally: " # toCalc.result # endl;
    toCalc:printCalc();
    // testChain = <09 08 07 06 05 04 03 02 01 00>;
    // nCalc testCalc;
    // testCalc:Create(1, 2);
    // testCalc:convert2String(testChain);
    // aNumber = 18446744073709551616
    // bNumber = 18446744073709551615
}