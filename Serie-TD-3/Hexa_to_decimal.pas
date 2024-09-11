
Program base16;

Function base16_to_base(N : String;B2:Integer): Longint;
Var
  L,K,P ,S,E,U,D,M: Longint;
  CH, ray: Char;
  err: Integer;
Begin
  L := Length(N);
  K := L;
  P := 1;
  S := 0;
  For K:=L Downto 1 Do
    Begin
      CH := N[K];
      If (CH >= 'A') And (CH <= 'F') Then
        E := Ord(CH) - Ord('A') + 10
      Else
        If (CH >='0')And (CH <= '9')Then
          Begin
            Val(CH,E,err);
          End;
      S := S + E * P;
      P := P * 16;
      // End;
    End;
		 D := S ;
  P := 1;
  U := 0;
  While D > 0 Do
    Begin
      M := D Mod B2;
      D := D Div B2 ;
      U := U + M*P ;
      P := P*10;
    End;
	base16_to_base := U;
End;
//--------------------------------------------------
Var
  CHIFFRE : String;
  OP : Longint;
Begin
  Writeln('enter the hexa number ');
  Readln(CHIFFRE);
  OP := base16_to_base(CHIFFRE,10);
  Writeln(OP);
  Readln;
End.
