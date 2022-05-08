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
procedure nCalc.Copy(copy2this){
    nCalc copy2this;
    // copy2this:Create("0", "0", "*");
    
    copy2this.nr1 = this.nr1;
    copy2this.nr1decPos = this.nr1decPos;
    
    copy2this.nr2 = this.nr2;
    copy2this.nr2decPos = this.nr2decPos;
    
    copy2this.hasDP = TRUE;
    copy2this.decCount = this.decCount;
    
    copy2this.operator = this.operator;
    copy2this.result = this.result;
    copy2this.swap = this.swap;
    // return copy2this;

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

procedure nCalc.swapNrs(){
    tmpN1 = this.nr1;
    this.nr1 = this.nr2;
    this.nr2 = tmpN1;
    ~tmpN1;
    this.swap = TRUE;
}

procedure nCalc.leading0(mode){
    cut0 = <>;
    switch (mode){
        case(1):
            cut0 = &this.nr1;
            break;
        case(2):
            cut0 = &this.nr2;
            break;
        case(3):
            cut0 = &this.result;
            break;
    }
    runLoop = TRUE;
    idx = 0;
    while(runLoop){
        // echo "this.result[" # form("%d", idx) # "]: " # this.result[idx] # endl;
        switch (cut0[idx]) {
            case ("0"):
                idx++;
                break;
            case (","):
                runLoop = FALSE;
                cut0 = "0" # cut0[idx..$];
                break;
            default:
                runLoop = FALSE;
                cut0 = cut0[idx..$];
                break;
        }
        if  (sizeof(cut0) == 0){
            cut0 = "0";
            runLoop = FALSE;
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

procedure nCalc.divi(){
    // echo "divi()...\n";
    nCalc restoreThis;
    restoreThis:Create("0", "0", "/");
    this:Copy(&restoreThis);
    this:leading0(1);
    this:leading0(2);
    this:Create(this.nr1, this.nr2, "/");

    // echo "this.nr1: " # this.nr1 # endl;
    // echo "this.nr2: " # this.nr2 # endl;

    if (this.nr1 == "0"){
        if (this.nr2 == "0"){
            this.result = "!UNDEFINED!";
            return;
        }else{
            this.result = "0";
            return;
        }
    }else{
        if (this.nr2 == "0"){
            this.result = "!UNDEFINED!";
            return;
        }else{
            if (this.nr2 == 1){
                this.result = &this.nr1;
                return;
            }
        }
    }

    // echo "|==========================================>\n";
    // echo "|>>> calc sols\n";

    decPlaces = 0;
    decP_c = 0;

    sols = <>;
    nCalc prep;
    prep:Create("0", "0", "*");
    // prep:printCalc();
    pIdx = 0;
    while (pIdx < 10){
        prep.nr1 = form("%d", pIdx);
        prep:leading0(1);
        // // echo "prep.nr1: " # form("%C", prep.nr1) # endl;
        prep.nr2 = this.nr2;
        prep:leading0(2);
        // // echo "prep.nr2: " # form("%C", prep.nr2) # endl;
        prep:mult();
        // prep:printCalc();
        sols.(pIdx) = prep.result;
        pIdx++;
    }
    ~prep;
    // echo "|<<< done calcing sols\n";
    // echo "|------------------------------------------>\n";

    nCalc inbtw;
    inbtw:Create("0", "0", "-");

    // echo "|==> entering main loop...\n";
    done = FALSE;
    curPosA = 0;
    decPSet = FALSE;
    above = this.nr1[curPosA];
    curPosA++;
    below = &this.nr2;
    while (curPosA <= sizeof(this.nr1)){
        if (done){
            break;
        }
        // maxAB = maxi(&above, &below);
        // echo "|     above: " # above # endl;
        // echo "|     below: " # below # endl;
        // echo "|     this:\n";
        // this:printCalc();

        // echo "|------------------------------------------>\n";
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
                            idx++;
                            carry = 1;
                            maxAB = maxi(&above, &sols.(idx));
                            break;
                        // first run; above is greater so -> go up 
                        case (0):
                            // echo "|          switch(carry) -> (0)\n";
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
        // echo "|<<< solfinder done\n";
        // echo "|------------------------------------------>\n";
        // echo "|>>> final calculation before rerun...\n";
        this.result = this.result # form("%d", idx);

        inbtw.nr1 = &above;
        inbtw.nr2 = &sols.(idx);
        inbtw:subt();
        // echo "|     inbtw:\n";
        // inbtw:printCalc();
        above = inbtw.result;
        removeP0(&above);
        // echo "|>>> check if next digit exists...\n";
        if (curPosA < sizeof(this.nr1)){
            // echo "|     next digit exists -> appending to above and curPosA++\n";
            if(this.nr1[curPosA] == ","){
                curPosA++;
                if (curPosA >= sizeof(this.nr1)){
                    if (!decPSet){
                        this.result = this.result # ",";
                        decPSet = TRUE;
                    }

                }
            }
            above = above # this.nr1[curPosA];
            curPosA++;
        }else{
            
            decPlaces++;
            if(decPlaces == 100000){
                decP_c++;
                nCalc tmpDecpl;
                tmpDecpl:Create(form("%d",decP_c), "100000", "*");
                // tmpDecpl:printCalc();
                tmpDecpl:mult();
                echo "temporary result with " # tmpDecpl.result # " decimal places:" # this.result # endl # endl # endl;
                ~tmpDecpl;
                decPlaces = 0;
            }
            // echo "|     next digit doesnt exists -> appending ',' to result and '0' to above\n";
            if (above != "0"){
                if (!decPSet){
                    this.result = this.result # ",";
                    decPSet = TRUE;
                }
            }else{
                done = TRUE;
            }
            above = above # "0";
        }
        removeP0(&above);
        // echo "|<<< check for next digit done\n";
        // echo "|     above: " # above # endl;
        // echo "|     n1len: " # form("%d", sizeof(this.nr1)) # endl;
        // echo "|     curPosA: " # form("%d", curPosA) # endl;
        // echo "|     this:\n";
        // this:printCalc();
        // echo "|======> restart\n";
        // echo "|==========================================>\n";

    }
    // echo "this.result (hex): " # form("%C", this.result) # endl;
    removeP0(&this.result);
    restoreThis.result = this.result;
    restoreThis:Copy(&this);
    ~restoreThis;

    // echo "divi() done!\n";
}

procedure nCalc.mult(){
    // echo "--------------> multi()...\n";

    if (this.nr1 == "0"){
        this.result = "0";
        this:leading0(3);
        return;
    }else{
        if(this.nr1 == "1"){
            this.result = &this.nr2;
            this:leading0(3);
            return;
        }
    }
    if(this.nr2 == "0"){
        this.result = "0";
        this:leading0(3);
        return;
    }else{
        if(this.nr2 == "1"){
            this.result = &this.nr1;
        this:leading0(3);
            return;
        }
    }

    nCalc add2;
    add2:Create("0","0","+");
    nCalc res;
    n1len = sizeof(this.nr1);
    n2len = sizeof(this.nr2);

    if (maxInt(n1len, n2len) == 1){
        // tmp1 = this.nr1;
        // this.nr1 = this.nr2;
        // this.nr2 = tmp1;
        // ~tmp1;
        this:swapNrs();

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
    }
    this:leading0(3);
    // removeP0(&this.result);
    // echo "--------------> multi() done!\n";
}

procedure nCalc.subt(){
    swap = FALSE;
    
    nr1Len = sizeof(this.nr1)-1;
    nr2Len = sizeof(this.nr2)-1;
    biggerLen = max(nr1Len,nr2Len);
    if (biggerLen == -1){
        // nr2 is longer (therefore bigger) -> swap nr1 with nr2
        // tmpNr1 = this.nr1;
        // this.nr1 = this.nr2;
        // this.nr2 = tmpNr1;
        // ~tmpNr1;
        // this.swap = TRUE;

        this:swapNrs();
        
        nr1LenTMP = nr1Len;
        nr1Len = nr2Len;
        nr2Len = nr1LenTMP;
        ~nr1LenTMP;
        swap = TRUE;
    }else{
        if (biggerLen == 0){
            // nr1 and nr2 are same length -> find bigger number
            maxiRet = maxi(this.nr1, this.nr2);
            if(maxiRet == 0){
                // nr1 is equal to nr2 -> result = 0
                this.result = "0";
                return;
            }else{
                if (maxiRet == -1){
                    // echo "swap bc of biggerVal/maxi()\n";
                    // tmpNR1 = this.nr1;
                    // this.nr1 = this.nr2;
                    // this.nr2 = tmpNR1;
                    // this.swap = TRUE;

                    this:swapNrs();

                    nr1Len = sizeof(this.nr1)-1;
                    nr2Len = sizeof(this.nr2)-1;
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
    this:leading0(3);
    if(swap){
        this.result = "-" # this.result;
    }

}

procedure nCalc.addi(){
    carry = 0;
    result = <>;

    nr1Len = sizeof(this.nr1)-1;
    nr2Len = sizeof(this.nr2)-1;

    biggerLen = max(nr1Len, nr2Len);

    if (biggerLen == -1){
        // nr2 longer than nr1 -> swap this.nr1 and this.nr2 and its according lengths 
        // tmpNr1 = this.nr1;
        // this.nr1 = this.nr2;
        // this.nr2 = tmpNr1;
        // ~tmpNr1;
        
        this:swapNrs();

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