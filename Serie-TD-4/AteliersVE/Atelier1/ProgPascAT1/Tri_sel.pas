Procedure TRI_SEL (Var T : Tab1D; Tai: Tind);
//trie les éléments de T par ordre croissant : méthode par sélection
Var
  j, Indice : Integer;
  //-----------------------------------------------------------
	Procedure PERMUT (Var A, B: Longint);
	//permute les contenus de A et B
	Var
	  Tmp: Longint;
	Begin //Permut
	  Tmp := A;
	  A := B;
	  B := Tmp;
	End; //fin Permut
//-----------------------------------------------------------
	Function indDuMin (T: Tab1D; Binf, Tai: Tind): Tind;
	//donne l'indice du plus petit élément dans une portion du tableau
	Var
	  Ind, i: Integer;
	Begin //inDuMin
	  Ind := Binf;
	  For i := (Binf+1) To Tai Do
	    Begin
	      If T[i] < T[Ind] Then Ind := i;
	    End;
	  indDuMin := Ind;
	End; //fin IndDuMin
//-----------------------------------------------------------
Begin //TRISEL
  For j := 1 To (Tai -1) Do
    Begin
      Indice := IndDuMin (T, j, Tai);
      PERMUT (T[j], T[Indice]);
    End;
End; //fin TRISEL