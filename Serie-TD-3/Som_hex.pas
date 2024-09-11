Program Some_Base_16;
Uses IsaacLibr,Crt;
Var
  chiffre1,chiffre2 ,Hex: String;
  B , Som , K1 , K2 : Longint;
Begin
  Writeln('Enter le nombre N1 en hexadescimal : ');
  Readln(chiffre1);
  Writeln('Enter le nombre N2 en hexadescimal : ');
  Readln(chiffre2);
  Writeln('Entrer la Base (B) : ');
  Readln(B);
  K1 := base16_to_base(chiffre1,B);
  K2 := base16_to_base(chiffre2,B) ;
  Som := Som_base(K1,K2,B);
  Hex := ToHex(Som, B,16) ;
  Writeln('la somme ',chiffre1,' +  ',chiffre2,'  =  ',Hex);
  Readln;
End.