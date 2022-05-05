include ("std.inc");

procedure main(){
    // str = "Hallo dies wird von nullen ueberschrieben";
    // str[0..$] = "0";

    // echo str;

    a = 5;
    b = a;
    a++;
    echo "a: " # form("%d", a) # endl;
    echo "b: " # form("%d", b) # endl;


}