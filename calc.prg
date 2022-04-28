include("std.inc");
include ("conv.inc");
include ("./ncalc.gpp.inc");
include ("./ncalc.def.inc");
include ("./ncalc.fnc.inc");
// include ("ascii.inc");
// include ("./convert.inc");

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
    idx1 = 500;
    idx2 = 0;
    toBreak = FALSE;
    nCalc test;
    while(idx1 < 550){
        while(idx2 < 20000){
            // echo "idx1: " # form("%d", idx1) # ", idx2: " # form("%d", idx2) # endl;

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
                echo "Calculation error at:\n";
                test:printCalc();
                echo "Expected: " # form("%d",sol) # ", but was: " # test.result # endl;
                toBreak = TRUE;
                break;
            }
            else{
                // echo "-----------------------------------------\n";
                // echo "calc was correct: " # endl;
                // test:printCalc();
                // echo "-----------------------------------------\n";
                a = 0;
            }
            idx2++;
        }
        if(toBreak){
            break;
        }
        idx2 = 0;
        idx1++;
    }
    echo "test successfull -> no errors encountered\n";
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

procedure selfTestAS(){
    breaking = FALSE;
    idx1 = 1;
    idx2 = 1;
    counter = 0;
    nCalc testA;
    nCalc testS;
    while (idx1 < 150){
        while (idx2 < 300){
            ~testA;
            ~testS;
            nCalc testA;
            nCalc testS;
            testA:Create(form("%d",idx1), form("%d",idx2), "+");
            testA:addi();
            // testA:printCalc();
            testS:Create(testA.result, form("%d",idx2), "-");
            testS:subt();
            // testS:printCalc();
            if (testS.result != form("%d",idx1)){
                echo "Encountered error at idx1: " # form("%d",idx1) # ", idx2: " # form("%d",idx2) # ".\n";
                echo "Expected result: " # form("%d",idx1) # ", but was: " # testS.result # endl;
                echo ".-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n";
                testA:printCalc();
                testS:printCalc();
                breaking = TRUE;
                break;
            }else{
                echo "pass: " # form("%d", counter) # endl;
            }
            counter++;
            idx2++;
        }
        if(breaking){
            break;
        }
        idx2 = 0;
        idx1++;
    }
}

procedure selfTestSA(){
    breaking = FALSE;
    idx1 = 1;
    idx2 = 1;
    counter = 0;
    nCalc testA;
    nCalc testS;
    while (idx1 < 150){
        while (idx2 < 300){
            ~testA;
            ~testS;
            nCalc testA;
            nCalc testS;
            testS:Create(form("%d",idx1), form("%d",idx2), "-");
            testS:subt();
            // testS:printCalc();
            testA:Create(testA.result, form("%d",idx2), "+");
            testA:addi();
            // testA:printCalc();
            if (testS.result != form("%d",idx1)){
                echo "Encountered error at idx1: " # form("%d",idx1) # ", idx2: " # form("%d",idx2) # ".\n";
                echo "Expected result: " # form("%d",idx1) # ", but was: " # testS.result # endl;
                echo ".-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n";
                testA:printCalc();
                testS:printCalc();
                breaking = TRUE;
                break;
            }else{
                echo "pass: " # form("%d", counter) # endl;
            }
            counter++;
            idx2++;
        }
        if(breaking){
            break;
        }
        idx2 = 0;
        idx1++;
    }
}

procedure main (){



    // testAdd();
    // testSub();
    // selfTestAS();
    // selfTestSA();

    idx = 1;
    argLen = $ARGV;
    if (argLen == 1){
        echo "Usage:" # endl # ARGV.[0] # " [OPTION] [TERM]" # endl;
        echo "OPTIONS:\n";
        echo "         -calc [TERM]  ->  Calculates passed term\n";
        echo "         -tas          ->  Selftest of Addition to Subtraction\n";
        echo "         -calc         ->  Selftest of Subtraction to Addition\n";
        exit(1);
    }
    while (idx < argLen){
        switch (ARGV.[idx]){
            case "-calc":
                idx++;
                term = ARGV.[idx];
                nCalc toCalc;
                toCalc = splitTerm(&term);
                echo "----------------------------------------\n";
                // echo "finally: " # toCalc.result # endl;
                toCalc:printCalc();
                break;
            case "-tas":
                selfTestAS();
                break;
            case "-tsa":
                selfTestSA();
                break;
            case "--help":
                echo "Usage:" # endl # ARGV.[0] # " [OPTION] [TERM]" # endl;
                echo "OPTIONS:\n";
                echo "         -calc [TERM]  ->  Calculates passed term\n";
                echo "         -tas          ->  Selftest of Addition to Subtraction\n";
                echo "         -calc         ->  Selftest of Subtraction to Addition\n";
                break;
            default:
                echo "unknown flag: " # ARGV.[idx] # endl;
                exit(1);
        }
        idx++;
    }

    // echo sizeof(ARGV.[1]);

}