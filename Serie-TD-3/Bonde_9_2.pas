Program Bonde_9_2 ;
Uses Crt;

Function NBPOS(n : Longint): Longint;
// Function to calculate the number of digits in a number
Var
  i: Longint;
Begin
  i := 0;
  While n <> 0 Do
    Begin
      i := i+1;
      n := n Div 10;
    End;
  NBPOS := i;
End;
//----------------------------------------------------

Function PUISS(x,y : Longint): Longint;
// Function to calculate x raised to the power y
Var
  F,i: Longint;
Begin
  F := 1;
  For i:= 1 To y Do
    F := F*x;
  PUISS := F;
End;
//------------------------------------------------------

Function SOM_CH(n : Longint): Longint;
// Function to calculate the sum of digits in a number
Var
  A , P,i : Integer;
Begin
  P := 0;
  For i:=1 To NBPOS(n) Do
    Begin
      A := n Mod 10 ;
      P := P + A ;
      n := n Div 10;
    End;
  SOM_CH := P ;
End;
//---------------------------------------

Function CROISSANT(N:Longint): Longint;
Var
  croiss,sauvN: Longint;
  c: Integer;
Begin
  croiss := 0;
  For c:=1 To 9 Do
    Begin
      sauvN := N;
      While sauvN>0 Do
        Begin
          If sauvN Mod 10=c Then croiss := 10*croiss+c;
          sauvN := sauvN Div 10;
        End;
    End;
  CROISSANT := croiss;
End;
//---------------------------------------------
//---------------------------------------------
Var
  B,A,C,cpt,D : Longint;
Begin
  Writeln('Ce code donne la bomde des 9 : ');
  cpt := 0;
  For A:= 123 To 987 Do
    Begin
      For B:= 124 To 987 Do
        Begin
          For C:= 312 To 987 Do
            Begin
              D := A*1000000 + B*1000 + C ;
              If (A+B=C) And (A<B) And (CROISSANT(D) = 123456789) And ( SOM_CH(C) = 18 ) Then
                Begin
                  cpt := cpt + 1;
                  Writeln(cpt ,' \\  ',A,'    +    ',B,'    =    ',C);
                End;
            End;
        End;
    End;
  Readln;
End.