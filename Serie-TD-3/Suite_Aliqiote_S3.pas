program S_Aliquote_S3;
Function SOMDIV(N:Longint): Longint;
Var
  i,som: Integer;
Begin
  som := 1;
  For i:=2 To (N Div 2) Do
    Begin
      If (N Mod i=0) Then
        Begin
          som := som +i;
        End;
    End;
  SOMDIV := som;
End;
//{18}--------------------------------------------------------

Procedure Suit_Aliquote(N : Longint; Var order:Integer;Var S : Longint);
Var
  D,k : Longint;
Begin
  Write('la sequance des nombre est : ',N , ' ');
  D := N ;
  order := 0 ;
  While (N <> 1) And (D <> k) Do
    Begin
      S := SOMDIV(N) ;
      WriteLn(S,' ');
      N := S;
      k := N ;
      S := 0 ;
      order := order + 1 ;
    End ;
  If N = 1 Then
    Begin
      If order = 1 Then
        Writeln('Le nombre ', D ,' est un nombre premier ');
    End
  Else
    Begin
      If order = 1 Then
        Writeln('Le nombre ',N ,' est nombre social et parfait d''ordre 1 ')
      Else If order = 2 Then
             Writeln('le nombre  ',N,' est un nombre social et ami d''ordre 2')
      Else
        Writeln('le nombre  ',N,' est un nombre social d''ordre  ',order );
    End;
End;

Var  N,order,S : Integer;
Begin
WriteLn('Enter the number : ');
Readln(N) ;
Suit_Aliquote(N,order,S);
Readln;
end.