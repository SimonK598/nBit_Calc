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

    procedure divi ();
    procedure mult ();
    procedure subt ();
    procedure addi ();

    procedure printCalc();
    procedure swapNrs();
    procedure leading0(mode);
    procedure following0(n1dc,n2dc);
    procedure addDP(mod);

    procedure Create(nr1, nr2, op);
    procedure Copy(copy2this);
}