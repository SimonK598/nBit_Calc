struct nCalc{
    .nr1;
    // .nr1decCount;
    .nr1decPos;

    .nr2;
    // .nr2decCount;
    .nr2decPos;
    
    .hasDP;
    .decCount;

    .operator;
    .result;
    .swap;

    function divi ();
    function mult ();
    function subt ();
    function addi ();

    procedure printCalc();
    procedure leading0();
    procedure following0(n1dc,n2dc);
    procedure addDP(mod);

    procedure Create(nr1, nr2, op);
}