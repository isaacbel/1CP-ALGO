Program EXO_11 ;
Var
  N , D , j ,A,B,B2,C ,chiffre : Longint ;
Begin
  Writeln('Enter le nombre : ');
  Readln(N);
  Writeln('Enter le chiffre : ');
  Readln(chiffre);
  j := 1 ;
  D := N ;
  Repeat
    A := N Mod 10 ;
    N := N Div 10 ;
    j := j*10;
  Until (A = chiffre) Or (N = 0) ;

	If N = 0 Then
	   Writeln('Le chiffre n''est pas dans le nombre N ')

  Else
	 Begin
    B := D Div j ;
    B2 := ((D Mod j )Mod (j Div 10))*10;
    C := B*j + B2 ;
    Writeln(C);
	End;	
  Readln;
End.