Program CompDecomChar;
//TP2 1CP 2022-2023
Uses wincrt;
Const MaxLM = 7;
      MaxCM = 5;
			MaxV = 35;
			Max = 100;
Type  Tind = 1..Max;
      Tindl = 1..MaxLM;
			Tindc = 1..MaxCM;
      Tab1D = Array[Tind] of Integer;
			Tab2D = Array[Tindl,Tindc] of Integer;
Var M:Tab2D;
    C,V:Tab1D;
		TaiV, TaiC : Tind;
		Ch, Chl : integer;
		Nbl : Tindl;
		Nbc : Tindc;
		T, M1, M2, M3, M4, M5 : Boolean;
//---------------------------------------------------
// Procedure de lecture d'une matrice ou tableau 2D
Procedure Lect2D(Var T:Tab2D; Var NL:TindL; Var NC:TindC);
Var
  i, j: Integer;
Begin
  Writeln('Donner le nombre de lignes du tableau: ');
  Readln(NL);
  Writeln('Donner le nombre de colonnes du tableau: ');
  Readln(NC);
  For i:=1 To NL Do
    Begin
      For j:=1 To NC Do
        Begin
          Write('T[',i,',',j,']= ');
          Read(T[i, j]);
        End;
    End;
End;
//--------------------------------------------------
//Module d'ecriture d'un tableau 2D ou Matrice
Procedure Ecrire2D(T:Tab2D; NL:TindL; NC:TindC);
Var
  i, j: Integer;
Begin
  For i:=1 To NL Do
    Begin
		  Write('     ');
      For j:=1 To NC Do
        Begin
          Write(T[i,j],' ');
        End;
      Writeln;
    End;
End;
//---------------------------------------------
//Procedure d'ecriture des valeus d'un tableau 1D (vecteur)
Procedure Ecrire1D(T:Tab1D; Tai:Tind);
Var
  i: Tind;
Begin
  For i:=1 To Tai Do
    Begin
      Write(T[i], '|');
    End;
		Writeln;
End;
//------------------------------------------------------
Procedure LectAffM (Var M : Tab2D; Var Nbl :Tindl; Var Nbc : Tindc);
Begin //LectAffM
  Writeln;
  Writeln ('   Lecture et Affichage de la matrice M[7,5] du caractere a compresser');
	Writeln ('   -------------------------------------------------------------------');
  Writeln ('   1. ------> Lecture de la matrice');
 	Writeln ('   2. ------> Jeu essai predefini');
	Writeln;
	Write   ('   Choix le lecture ? ');
	Readln (Chl);
	Writeln;
	Case Chl Of
	1: Begin // Avec lecture de la matrice M
			 Writeln (   'Lecture de la matrice');
			 Lect2D (M, Nbl, Nbc);
			 Writeln;
			 Writeln('   Valeurs de la matrice');
	     Writeln('   ---------------------');
			 Ecrire2D (M, Nbl, Nbc);
			 Writeln ('   -------------------------------------------------------------------');
	   End;
	2: Begin // Avec jeu essai predefini
  		     // Jeu essai 1 : Caractere A
			 (*
			  M[1,1]:=0; M[1,2]:=0; M[1,3]:=1; M[1,4]:=0; M[1,5]:=0;
				M[2,1]:=0; M[2,2]:=1; M[2,3]:=0; M[2,4]:=1; M[2,5]:=0;
			  M[3,1]:=1; M[3,2]:=0; M[3,3]:=0; M[3,4]:=0; M[3,5]:=1;
				M[4,1]:=1; M[4,2]:=1; M[4,3]:=1; M[4,4]:=1; M[4,5]:=1;
				M[5,1]:=1; M[5,2]:=0; M[5,3]:=0; M[5,4]:=0; M[5,5]:=1;
				M[6,1]:=1; M[6,2]:=0;	M[6,3]:=0; M[6,4]:=0; M[6,5]:=1;
				M[7,1]:=1; M[7,2]:=0; M[7,3]:=0; M[7,4]:=0; M[7,5]:=1;*)
  //*--------------------------------------------------------------
			  // Jeu essai 2 : le chiffre 8
				M[1,1]:=1; M[1,2]:=1; M[1,3]:=1; M[1,4]:=1; M[1,5]:=1;
				M[2,1]:=1; M[2,2]:=0;	M[2,3]:=0; M[2,4]:=0;	M[2,5]:=1;
				M[3,1]:=1; M[3,2]:=0; M[3,3]:=0; M[3,4]:=0;	M[3,5]:=1;
				M[4,1]:=1; M[4,2]:=1; M[4,3]:=1; M[4,4]:=1;	M[4,5]:=1;
				M[5,1]:=1; M[5,2]:=0; M[5,3]:=0; M[5,4]:=0;	M[5,5]:=1;
				M[6,1]:=1; M[6,2]:=0;	M[6,3]:=0; M[6,4]:=0;	M[6,5]:=1;
				M[7,1]:=1; M[7,2]:=1;	M[7,3]:=1; M[7,4]:=1; M[7,5]:=1;
				Nbl:=7;
				Nbc:=5;
		    Ecrire2D (M, Nbl, Nbc);
			 	Writeln ('   -------------------------------------------------------------');
	End
	Else Writeln ('   Erreur de choix');
	End;
End; //LectAffM
//------------------------------------------------
Procedure ConvMenV (M:Tab2D; Nbl:Tindl; Nbc:TindC; Var V:Tab1D; Var TaiV :Tind);
Var i, j, k : integer;
Begin //ConvMenV
  Writeln;
	Writeln ('   Conversion de M[7,5] en un vecteur V[35] avec affichage de V ');
	Writeln ('   -------------------------------------------------------------');
	i:=0;
	while i<Nbl Do
	Begin
	  for j:=1 to Nbc Do
		Begin
		  k:=(i*Nbc)+j ; 
		  V[k]:=M[i+1,j];
		end;
		i:=i+1;
	end;
	TaiV := Nbl*Nbc;
	Writeln('Valeurs du vecteur V');
	Writeln('--------------------');
	Ecrire1D (V, Taiv); 
End; //ConvMenV
//------------------------------------------------
Procedure ConvVenC (V:Tab1D; TaiV : Tind; Var C : Tab1D; Var TaiC : Tind);
Var k, p, i :integer;
Begin //ConvVenC
	Writeln;
	Writeln ('   Compression de V[35] en un vecteur C  avec affichage de C');
	Writeln ('   ---------------------------------------------------------');
	c[1]:=v[1];
	p:=2;
	k:=1;
	For i:=1 to Taiv-1 Do
	Begin
	  if (V[i]=V[i+1]) Then
		Begin
      k:=k+1;
		  C[p]:=k;
		end
		Else
		Begin
			k:=1;
			p:=p+1;
			C[p]:=1;
		end;
  end;
	Writeln('   Valeurs du vecteur C');
	Writeln('   --------------------');
	TaiC := p;
	Ecrire1D (C, TaiC);
End; //ConvVenC
//------------------------------------------------
Procedure DConvCenV (C:Tab1D; TaiC : Tind; Var V : Tab1D; Var TaiV : Tind);
Var i, j, b, k, rp : integer;
    d : Tab1D;
Begin //DConvCenV
	Writeln;
	Writeln ('   DeCompression de C en un vecteur V  avec affichage de V');
	Writeln ('   -------------------------------------------------------');
	k:=1;
	b:=c[1];
	for i:=2 to TaiV Do
	Begin
	  rp:=c[i];
		for j:=1 to rp Do
		Begin
		  d[k]:=b;
			k:=k+1;
		end;
		b:=1-b;
	end;
	Writeln('   Valeurs du vecteur V apres decompression de C');
	Writeln('   ---------------------------------------------');
	Ecrire1D (V, Taiv);
End; //DConvCenV
//------------------------------------------------
Procedure ConvVenM (V:Tab1D; TaiV : Tind; Var M : Tab2D; Nbl:Tindl; Nbc: Tindc);
Var i,j,k : integer;
Begin //ConvVenM
	Writeln;
  Writeln ('  5. Conversion de V en une matrice M avec affichage de M');
	Writeln('   --------------------------------------------------------');
	k:=1;
	For i:=1 to Nbl Do
	  For j:=1 to Nbc Do
		Begin
		  M[i,j]:= V[k];
			k:=k+1;
		End;
  Writeln;
  Writeln('   Valeurs de la matrice');
  Writeln('   ---------------------');
	Ecrire2D (M, Nbl, Nbc);
End; //ConvVenM
//------------------------------------------------
Begin //  Principal
	  Writeln ('   -------------- ATELIER 3  ------------------');
	  Writeln ('   --------------------------------------------');
		//Initialisitation des variables booleennes relatives aux traitement des modules
	  M1:=False; M2:=False; M3:=False; M4:=False;
	Repeat
	  Writeln;
	  Writeln ('   -------------------------- Menu des modules --------------------------');
	  Writeln ('   ----------------------------------------------------------------------');
		Writeln ('   1. Lecture et Affichage de la matrice M[7,5] du caractere a compresser');
		Writeln ('   2. Conversion de M[7,5] en un vecteur V[35] avec affichage de V ');
		Writeln ('   3. Compression de V[35] en un vecteur C  avec affichage de C');
		Writeln ('   4. DeCompression de C en un vecteur V  avec affichage de V');
		Writeln ('   5. Conversion de V en une matrice M avec affichage de M');
		Writeln ('   6. Quit');
		Writeln ('----------------------------------------------------------------------');
		Writeln;
		Write   ('   Votre Choix ? ');
		Readln  (Ch);
    //-----------------------------------------------------------------------------
		Case Ch Of
			1: Begin //1
			      M1:=True;
						LectAffM (M, Nbl, Nbc);
			   End;  //1
     //-----------------------------------------------------------------------------
			2: Begin //2
						If (M1=False) then Writeln ('Matrice M non lue')
						Else
						Begin
						  M2:= True;
							ConvMenV (M, Nbl, Nbc, V, TaiV);
						End;
			   End;  //2
		 //-----------------------------------------------------------------------------
			3: Begin //3
			    M3:=True;
					T := (M1 AND M2);
					If (T = False) Then Writeln ('Matrice M non lue OU non convertie en V') 
			    Else ConvVenC (V, TaiV, C, TaiC);
			   End;  //3
			//-----------------------------------------------------------------------------
			4: Begin //4
			     M4 := True;
					 T:= (M1 And M2 And M3);
					 If (T = False) Then Writeln ('M, V et C non disponibles') 
		       Else DConvCenV (C, TaiC, V, TaiV);
			   End;  //4
			//-----------------------------------------------------------------------------
			5: Begin //5
					 M5 := True;
					 T:= (M1 And M2 And M3 And M4);
					 If (T = False) Then Writeln ('M, V et C non disponibles')
		       Else ConvVenM (V, TaiV, M, Nbl, Nbc);
			   End;  //5
		 //-----------------------------------------------------------------------------
			6: Begin //6
					 Writeln ('   Fin du programme');
					 Exit;
			   End  //6
		  //-----------------------------------------------------------------------------
			 Else Writeln (   'Erreur de choix');
		 End; //Case
	   //-----------------------------------------------------------------------------
   Until readkey=chr(27);
End. //Principam