// Numbers (nr1/nr2) are literal hex values of chars in String ("0" -> [0x30], "12" -> [0x31,0x32])
procedure nCalc.Create(nr1, nr2, op){
    this.nr1 = nr1;
    nr1decCount = 0;
    this.nr1decPos = -1;
    nr1dec = FALSE;
    idx1 = 0;
    while(idx1 < sizeof (this.nr1)){
        if(nr1dec == TRUE){
            nr1decCount++;
        }
        if (this.nr1[idx1] == ","){
            nr1dec = TRUE;
            this.nr1decPos = idx1;
        }
        idx1++;
    }
    this.nr1 = this.nr1[0..(this.nr1decPos-1)] # this.nr1[(this.nr1decPos+1)..$];

    this.nr2 = nr2;
    nr2decCount = 0;
    this.nr2decPos = -1;
    nr2dec = FALSE;
    idx2 = 0;
    while(idx2 < sizeof (this.nr2)){
        if(nr2dec == TRUE){
            nr2decCount++;
        }
        if (this.nr2[idx2] == ","){
            nr2dec = TRUE;
            this.nr2decPos = idx2;
        }
        idx2++;
    }
    this.nr2 = this.nr2[0..(this.nr2decPos-1)] # this.nr2[(this.nr2decPos+1)..$];

    if (nr1dec == TRUE || nr2dec == TRUE){
        this:following0(nr1decCount, nr2decCount);
    }else{
        this.hasDP = FALSE;
        this.decCount = 0;
    }

    this.operator = op;
    this.result = <>;
    this.swap = FALSE;

}

procedure nCalc.printCalc(){
    echo "|-[printCalc]----------------------->\n";
    if (this.hasDP |==| <00>){
        echo "|this.nr1:         " # this.nr1 # endl;
    }else{
        this:addDP(1);
        echo "|this.nr1:         " # this.nr1 # endl;
    }
    if (this.hasDP |==| <00>){
        echo "|this.nr2:         " # this.nr2 # endl;
    }else{
        this:addDP(2);
        echo "|this.nr2:         " # this.nr2 # endl;
    }
    if (this.swap |==| <00>){
        echo "|this.swap:        FALSE" # endl;
    }else{
        echo "|this.swap:        TRUE" # endl;
    }
    echo "|this.operator:    " # this.operator # endl;
    echo "|this.result:      " # this.result # endl;
    if (this.hasDP |==| <00>){
        echo "|this.hasDP:       FALSE" # endl;
    }else{
        echo "|this.hasDP:       TRUE" # endl;
    }
    echo "|this.decCount:    " # form("%d", this.decCount) # endl;
    
    echo "|----------------------------------->\n";
}

procedure nCalc.leading0(){
    runLoop = TRUE;
    idx = 0;
    while(runLoop){
        switch (this.result[idx]) {
            case ("0"):
                idx++;
                break;
            case (","):
                runLoop = FALSE;
                this.result = "0" # this.result[idx..$];
                break;
            default:
                runLoop = FALSE;
                this.result = this.result[idx..$];
                break;
        }
    }
}
procedure nCalc.rmleading0(){
    runLoop = TRUE;
    idx = sizeof(this.result);
    idx = idx - 1;
    while(runLoop){
        switch (this.result[idx]) {
            case ("0"):
                idx = idx - 1;
                break;
            case (","):
                runLoop = FALSE;
                this.result = this.result[0..idx-1];
                break;
            default:
                runLoop = FALSE;
                this.result = this.result[0..idx];
                break;
        }
    }
}

procedure nCalc.following0(n1dc, n2dc){
    this.hasDP = TRUE;
    maxAB = maxInt(n1dc, n2dc);
    // echo "maxAB: " # form("%d", maxAB) # endl;
    switch (maxAB){
        case (1):
            this.decCount = n1dc;
            zeroApp = <>;
            decDiff = (n1dc - n2dc);
            idx = 0;
            while(idx < decDiff){
                zeroApp = zeroApp # "0";
                idx = idx + 1;
            }
            this.nr2 = this.nr2 # zeroApp;
            break;
        case (-1):
            this.decCount = n2dc;
            zeroApp = <>;
            decDiff = (n2dc - n1dc);
            idx = 0;
            while(idx < decDiff){
                zeroApp = zeroApp # "0";
                idx = idx + 1;
            }
            this.nr1 = this.nr1 # zeroApp;
            break;
        default:
        this.decCount = n1dc;
            break;
    }
}

procedure nCalc.addDP(mod){
    switch (mod){
        case 1:
            strLen = sizeof (this.nr1);
            strp1 = this.nr1[0..(strLen-this.decCount)-1];
            strp2 = this.nr1[(strLen-this.decCount)..$];
            this.nr1 = <>;
            this.nr1 = strp1 # "," # strp2;
            break;
        case 2:
            strLen = sizeof (this.nr2);
            strp1 = this.nr2[0..(strLen-this.decCount)-1];
            strp2 = this.nr2[(strLen-this.decCount)..$];
            this.nr2 = <>;
            this.nr2 = strp1 # "," # strp2;
            break;
        case 3:
            strLen = sizeof (this.result);
            if (this.operator == "*"){
                strp1 = this.result[0..(strLen-(this.decCount*2))-1];
                strp2 = this.result[(strLen-(this.decCount*2))..$];
            }else{
                strp1 = this.result[0..(strLen-this.decCount)-1];
                strp2 = this.result[(strLen-this.decCount)..$];
            }
            this.result = <>;
            this.result = strp1 # "," # strp2;
            break;
    }
}

// >>> Actual math  <<< 

function nCalc.divi(){
    echo "todo\n";
}

function nCalc.mult(){
    // echo "--------------> multi()...\n";

    nCalc add2;
    add2:Create("0","0","+");
    nCalc res;
    n1len = sizeof(this.nr1);
    n2len = sizeof(this.nr2);

    if (maxInt(n1len, n2len) == 1){
        tmp1 = this.nr1;
        this.nr1 = this.nr2;
        this.nr2 = tmp1;
        ~tmp1;
            
        n1len = sizeof(this.nr1);
        // echo "n1l: " # form("%d", n1len) # endl;
        n2len = sizeof(this.nr2);
        // echo "n2l: " # form("%d", n2len) # endl;
    }
    n2lc = sizeof(this.nr2);

    foll0 = "";
    foll10 = "";

    while (n1len > 0){
        while (n2len > 0){
            // echo "before sn1: " # this.nr1[n1len-1] # endl;
            // echo "before sn2: " # this.nr2[n2len-1] # endl;
            sn1 = scan("%d",this.nr1[n1len-1]);
            sn2 = scan("%d",this.nr2[n2len-1]);
            // echo "after sn1: " # form("%C", sn1) # endl;
            // echo "after sn2: " # form("%C", sn2) # endl;
            
            sn3 = form("%d", (sn1*sn2));

            sn3 = sn3 # foll0 # foll10;
            // echo "sn3: " # sn3 # endl;
            foll0 = foll0 # "0";

            add2:Create(add2.result, sn3, "+");
            add2:addi();
        
            n2len = n2len - 1;
        }
        foll0 = "";
        foll10 = foll10 # "0";
        n2len = n2lc;
        n1len = n1len - 1;
    }

    this.result =  add2.result;
    if (this.hasDP){
        this:addDP(3);
        this:rmleading0();
    }
    // echo "--------------> multi() done!\n";
}

function nCalc.subt(){
    swap = FALSE;
    
    nr1Len = sizeof(this.nr1)-1;
    nr2Len = sizeof(this.nr2)-1;
    biggerLen = max(nr1Len,nr2Len);
    if (biggerLen == -1){
        // nr2 is longer (therefore bigger) -> swap nr1 with nr2
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
    // carry for next left neighbour
    precarry = 0;
    result = <>;
    while (nr2Len >= 0){

        num1 = scan("%d",this.nr1[nr1Len]);
        num1 = num1 + precarry;

        num2 = scan("%d",this.nr2[nr2Len]);

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
        if(nr2Len == 0 && nr1Len == 0){
            if (num3 != 0){
                result = num3 # result;
            }
        }else{
            result = num3 # result;
        }

        nr1Len = nr1Len - 1;
        nr2Len = nr2Len - 1; 
    }

    while (nr1Len >= 0){
        num1 = scan("%d",this.nr1[nr1Len]);
        
        num1 = num1 + precarry;
        
        if(num1 == -1){
            num1 = 9;
            precarry = -1;
        }else{
            precarry = 0;
        }
        if(nr1Len == 0){
            if (num1 == 0){
                break;
            }
        }
        result = num1 # result;
        
        nr1Len = nr1Len - 1;
    }
    this.result = convert2String(result);

    if (this.hasDP){
        this:addDP(3);
    }
    this:leading0();
    if(swap){
        this.result = "-" # this.result;
    }

}

function nCalc.addi(){
    carry = 0;
    result = <>;

    nr1Len = sizeof(this.nr1)-1;
    nr2Len = sizeof(this.nr2)-1;

    biggerLen = max(nr1Len, nr2Len);

    if (biggerLen == -1){
        // nr2 longer than nr1 -> swap this.nr1 and this.nr2 and its according lengths 
        tmpNr1 = this.nr1;
        this.nr1 = this.nr2;
        this.nr2 = tmpNr1;
        ~tmpNr1;
        nr1LenTMP = nr1Len;
        nr1Len = nr2Len;
        nr2Len = nr1LenTMP;
        ~nr1LenTMP;
    }
    
    while (nr2Len >= 0){

        num1 = scan("%d",this.nr1[nr1Len]);

        num2 = scan("%d",this.nr2[nr2Len]);

        num3 = num1 + num2 + carry;

        if (num3 > 9){
            num3 = num3 - 10;
            carry = 1;
        }else{
            carry = 0;
        }

        result = num3 # result;

        nr1Len = nr1Len - 1;

        nr2Len = nr2Len - 1;
    }
    
    while (nr1Len >= 0){
        num1 = scan("%d",this.nr1[nr1Len]);

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

    if (carry != 0){
        result = carry # result;
    }
    this.result = convert2String(result);
    if(this.hasDP){
        this:addDP(3);
    }
}
// !>>> Actual math  <<<! 