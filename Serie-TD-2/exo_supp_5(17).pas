Program Exo_17 ;
Var
    N , i ,j ,k ,A,num : LongInt ;

Begin
   Writeln(' Enter le nombre N : ');
	 Readln(N);
	 i := 0 ;
	 j := 0;
	 k := 0 ;
	 num := N ;

	 While N > 0 Do
	   Begin
		    A := N mod 10 ;
				Case A Of
				 1: i := i + 1;
         2: j := j + 1;
         6: k := k + 1;
        end;
			N := N Div 10 ;
		End;

		if (i=0) And (j=0) And (k =0) Then
		   WriteLn('les nombre 1 , 2 et 6 n''exixte pas dans le nombre N ')
	 Else
	   Begin
	    writeln('Chiffre 1 : ', i, ' fois');
      writeln('Chiffre 2 : ', j, ' fois');
       writeln('Chiffre 6 : ', k, ' fois');
		End;
	 Readln;
	End.		 	 

						

			