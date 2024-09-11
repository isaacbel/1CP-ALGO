Program Atelier1_ME;
(*          ESI (1CPI)
Avec modules externes dans le meme repertoire
D'autres solutions existent dans par exemple un repertoire*)
(*--------------------------------------------------------*)
Uses Wincrt;
//----------------------------------------
Const max = 500;
  		maxL = 500;
  		maxC = 500;
Type
  		Tind = 1..max;
  		TindL = 1..maxL;
  		TindC = 1..maxC;
  		Tab1D = Array[Tind] Of Longint;
  		Tab2D = Array[TindL,TindC] Of Longint;
Var
		  x : Tab1D;
		  R: Tab2D;
		  tai : Tind;
		  i,j,k,m: Integer;
			Rep:Char;
//----------------------------------------
(* Modules Externes dans le meme repertoire que le programme principale*)
{$i Lect1D}
{$i Ecrire1D}
{$i Tri_Sel}
{$i Ecrire2D}
{$i PartCent}
{$i ElemFibo}
//---------------------------------------------
Procedure Init(Var T:Tab1D; Var Tai:Tind);
//Jeu d'essai, juste pour ne pas introduire à chaque fois les données
Begin
  Tai := 12;
  T[1] := 144;
  T[2] := 479;
  T[3] := 13;
  T[4] := 1;
  T[5] := 832040;
  T[6] := 22222;
  T[7] := 6765;
  T[8] := 234478;
  T[9] := 89;
  T[10] := 4768;
  T[11] := 15559;
  T[12] := 4568;
End; //init
//----------------------------------------
Begin //Principal
	Rep:='O';
	Repeat
	  Clrscr;
		Writeln;
		Writeln('   ------ Atelier 1 -----------');
		Writeln('   ----------------------------');
	  Init(x,Tai);  //Avec un jeu d'essai fixe
	  //Lect1D(x,tai); //Avec d'autres jeux d'essais
		Writeln('   Tableau de donnees X ');
		Writeln('   ---------------------');
	  Ecrire1D(x,Tai);
		Writeln('   ------------');
		//Writeln;
	  tri_Sel(x,tai);
		Writeln('   Tableau de donnees X trie ');
		Writeln('   --------------------------');
	  Ecrire1D(x,Tai);
		Writeln('   ------------');
	  i := 0;
	  //i est l_indice de la 1ère  ligne qui va contenir les éléments appartenant à la suite
	  j := 0;
	  //j est l_indice de la 2ième  ligne  des éléments dont la partie centrale et identique
	  k := 0;
	  //k est l_indice de la 3ième ligne qui va contenir les intrus
	  For m:=1 To tai Do
	    //pour prendre un à un les éléments du tableau X
	    Begin
	      If ElemFibo(x[m]) Then
	        Begin
	          i := i+1;
	          R[1,i] := x[m];
	        End
	      Else
	        If PartCent(x[m]) Then
	          Begin
	            j := j+1;
	            R[2,j] := x[m];
	          End
	      Else
	        Begin
	          k := k+1;
	          R[3,k] := x[m];
	        End;
	    End;
	  If i>j Then
	    Begin
	      If i > k Then m := i;
	    End
	  Else If j>k Then m := j
	  Else m := k;
	  //Writeln;
		Writeln('   Tableau R (2D) ');
		Writeln('   ---------------');
	  Ecrire2D(R,3,m);
	  Readln;
	Write('   Voulez-vous quitter ? : ');
	Readln(Rep);
 Until (Upcase(Rep)='O');
  Writeln;
  Writeln('Fin de programme');
End. //Fin Principal