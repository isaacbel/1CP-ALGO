Program Multiplication_Miroire ;
//-----------------------------------
Function PUISS(x,y : Longint): Longint;
Var
  F,i: Longint;
Begin
  F := 1;
  For i:= 1 To y Do
    F := F*x;
  PUISS := F;
End;
//-----------------------------------------
//----------------------------------------
Function permitation(n,P1,P2:Longint): Longint;
Var
  A, B, D : Longint;
Begin
  A := (n Mod PUISS(10,P1)) Div PUISS(10,P1-1);
  B := (n Mod PUISS(10,P2)) Div PUISS(10,P2-1);
  D := n - (A *PUISS(10,P1-1) + B *PUISS(10,P2-1)) + A*PUISS(10,P2-1) + B*PUISS(10,P1-1) ;
  permitation := D ;
End;
//------------------------------------------------

Function NBPOS(n : Longint): Longint;
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
//-------------------------------------------
Function Chiffre_Different2(N1,N2 : Longint): Boolean;
Var
  A1,A2,A3,B1,B2 : Integer;
  K : Boolean;
Begin
  A1 := N1 Mod 10;
  A2 := (N1 Mod 100) Div 10 ;
  A3 := N1 Div 100;
  B1 := N2 Mod 10 ;
  B2 := N2 Div 10 ;
  If (A1 <> A2) And (A2 <> A3) And (A1 <> A3) And (B1 <> B2) And (A1 <> B1) And (A1 <> B2) And (A2 <> B1)
	 And (A2 <> B2) And (A3 <> B1) And (A3 <> B2) And (B1 <> B2) And (A1 <> 0) And (A2 <> 0)
     And (A3 <> 0) And (B1 <> 0) And (B2 <> 0) Then
    K := True
  Else K := False ;
  Chiffre_Different2 := K ;
End;
//-------------------------------------
Var
  i,j,D1,D2,S,k,F : Integer;
Begin
  Writeln('Ce programme donne les nombre de multiplication miroire');
  k := 0;
  For i:= 123 To 987 Do
    Begin
      For j:= 12 To 98 Do
        Begin
          If Chiffre_Different2(i,j) = True Then
            Begin
              D1 := permitation(i,3,1);
              D2 := permitation(j,2,1);
              S := i*j ;
              F := D1*D2;
              If (S = F) Then
                Begin
                  k := k + 1;
                  Writeln(k,' || ',i,'  *  ',j,'  =   ',' ',D1,'  *  ',D2,'  =  ',S);
                End;
            End;
        End;
    End;
  Readln;
End.