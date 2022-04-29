
// Numbers (nr1/nr2) are literal hex values of chars in String ("0" -> [0x30], "12" -> [0x31,0x32])
procedure nCalc.Create(nr1, nr2, op){
    this.nr1 = nr1;
    nr1decCount = -1;
    nr1decPos = -1;
    nr1dec = FALSE;
    idx1 = 0;
    while(idx1 < sizeof (this.nr1)){
        if (this.nr1[idx1] == ","){
            nr1dec = TRUE;
            nr1decPos = idx1;
        }
        if(nr1dec == TRUE){
            nr1decCount++;
        }
        idx1++;
    }
    this.nr1 = this.nr1[0..(nr1decPos-1)] # this.nr1[(nr1decPos+1)..$];

    // echo "[Create] nr1: " # form("%C", this.nr1) # endl;
    this.nr2 = nr2;
    nr2decCount = -1;
    nr2decPos = -1;
    nr2dec = FALSE;
    idx2 = 0;
    while(idx2 < sizeof (this.nr1)){
        if (this.nr2[idx2] == ","){
            nr2dec = TRUE;
            nr2decPos = idx2;
        }
        if(nr2dec == TRUE){
            nr2decCount++;
        }
        idx2++;
    }
    this.nr2 = this.nr2[0..(nr2decPos-1)] # this.nr2[(nr2decPos+1)..$];

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

procedure nCalc.leading0(){
    minusSign = FALSE;
    idx = 0;
    while(TRUE){
        if(this.result[idx] == "0"){
            idx++;
        }else{
            if (this.result[idx] == "-"){
                minusSign = TRUE;
                idx++;
            }else{
                // remove 0s and add sign if needed
                if (minusSign){
                    this.result = "-" # this.result[idx..$];
                    break;
                }else{
                    this.result = this.result[idx..$];
                    break;
                }
            }
        }
    }
}

function nCalc.divi(){
    echo "todo\n";
}

function nCalc.mult(){
    echo "todo\n";
}

function nCalc.subt(){
    // echo "subt was called...\n";
    // this:printCalc();

    
    swap = FALSE;
    
    nr1Len = sizeof(this.nr1)-1;
    nr2Len = sizeof(this.nr2)-1;
    biggerLen = max(nr1Len,nr2Len);
    // echo "stage 1\n";
    if (biggerLen == -1){
        // nr2 is longer (therefore bigger) -> swap nr1 with nr2
        // echo "swap bc of biggerLen/max()\n";
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
                    // echo "swap bc of biggerVal/maxi()\n";
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
    // echo form("%C",result) # endl;


    // echo "calling convert2String...\n";
    this.result = convert2String(result);

    if(swap){
        this.result = "-" # this.result;
    }

    this:leading0();

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