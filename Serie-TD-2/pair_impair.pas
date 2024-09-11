Program EXO_8 ;
Var
  N , N1 ,N2 , P ,S , A : Longint ;
Begin
  Writeln('enter le nobre N : ');
  Readln(N);
  P := 1;
  S := 1;
  N1 := 0;
  N2 := 0 ;
  While N > 0 Do
    Begin
      A := N Mod 10 ;
      If (A Mod 2 = 0) Then
        Begin
          N1 := N1 + A*P ;
          P := P*10;
        End
      Else
        Begin
          N2 := N2 + A*S ;
          S := S*10 ;
        End;
      N := N Div 10 ;
    End;
  Writeln('le nombre pair est : ',N1);
  Writeln('le nombre impaire est : ',N2);
  Readln;
End.