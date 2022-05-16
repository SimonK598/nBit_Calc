include("std.inc");
include ("conv.inc");
include ("./ncalc.gpp.inc");
include ("./ncalc.def.inc");
include ("./ncalc.fnc.inc");


procedure main(){

    test = <01>;
    test = test << 2;
    echo form("%C", test);

    // echo "maxi: " # form("%d", maxi("10", "30"));

}