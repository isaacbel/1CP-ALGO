Program ExoRecord;
Uses Wincrt;
//Declaration du type enregistrement
Type
  TMot = Array[1..3,1..3] Of String;
  Objet = Record
    				C: Char;
    				NBC: Longint;
    				PlusD1: Boolean;
						Tm:Tmot;
  				End;
Var	O:Objet; //variable enregistrement
//-----------------------------------------
Function FreqCar(Mot:String;c:Char):Integer;
// fonction de la frequence d'apparition d'un caractere dans un mot du tableau
Var	i,Fc: Integer;
Begin
  Fc:= 0;
  For i:=1 To Length(mot) Do
    Begin
      If mot[i]=c Then
        Begin
          Fc:=Fc+1;
        End;
    End;
 FreqCar:=Fc;
End;
//-----------------------------------------
Function FreqCarTab(T:Tmot;c:Char):integer;
// fonction de la frequence d'apparition d'un caractere dans tout le tableau
Var NBC,i,j,Fc: Integer;
Begin
  NBC:=0;
  For i:=1 To 3 Do
  Begin
    For j:=1 To 3 Do
    Begin
			Fc:=FreqCar(T[i,j],c);
	    //if Fc<>0 then
			//Begin
			  NBC:=NBC+FC;
			//end;
		end;
	end;
FreqCarTab:=NBC;
End;
//-----------------------------------------
Function PlD1(Nbc:integer):Boolean;
//s'il ya plus d'un caractere dans le tableau
Begin
  if Nbc>1 then PlD1:=True
	else PlD1:=false;
End;
//-----------------------------------------
Procedure RemplirTmot(Var T:Tmot);
//Proc pour remplir les mots du tableau de l'enreg.
var i,j:integer;
Begin  // RemplirTmot
  Writeln('Donner les mots du tableau 3x3 ');
	writeln('-------------------------------');
  For i:=1 To 3 Do
    Begin
      For j:=1 To 3 Do
        Begin
          Write('T[',i,';',j,']= ');
          Readln(T[i,j]);
        End;
    End;
End; // Fin RemplirTmot
//-----------------------------------------
Procedure AfficherTmot(T:Tmot);
//la proc pour Afficher les mots du tableau de l'enreg.
Var i,j:integer;
Begin
	writeln('    Tableau des mots : ');
	writeln('    ------------------ ');
	For i:=1 To 3 Do
    Begin
      For j:=1 To 3 Do
        // boucle d'affichage du tableau
        Begin
          Write('   ',T[i,j]:10,' | ');
        End;
        Writeln;
    End;
end;
//-----------------------------------------
Procedure RemplirEnr(Var O:Objet);
//porocedure pour remlir l'enregistrement <Objet>
var 	Nc:integer;
Begin
	//utilisation de l'objet de type enregistrement
	with O do
	Begin
	  write('Caractere < c > de l''objet : ');
		readln(c);
		//Appel de la proc pour remplir les mots du tableau
		RemplirTmot(Tm);
		//Appel de la proc pour afficher le tableau
		AfficherTmot(Tm);
		//Appel de la fonc pour calculer la frequence de c dans le tableau
		NBC:=FreqCarTab(Tm,c);
		//Appel de la fonction pour savoir s''il ya plus de 1 caractere c
		PlusD1:=PlD1(NBC);
	end;
end;
//-----------------------------------------
Procedure AfficherEnr(O:Objet);
//Proc pour afficher des differents champs de l'enregistrement
Begin
	writeln;
	writeln('Objet');
	with O do
	Begin
	// affichage du caractere de l'enregistrement
		writeln('          Carac Rech = ',c);
  // affichage de la frequence du caractere de l'enregistrement
		writeln('       Nb Carac Rech = ',NBC); //la frequence de c
	// affichage <vrai> si le caractere est dans plus d'un mot
		writeln('   PlusD1 Carac Rech = ',PlusD1);
	// affichage du tableau des mots de l'enregistrement
			AfficherTmot(Tm);
	  writeln('Fin Objet');
	end;
end;
//-----------------------------------------
Begin //Principal
	writeln('Manipulation d''un Objet de type Enregistrement');
	writeln('-----------------------------------------------');
	writeln;
	repeat
	  RemplirEnr(O);
	  AfficherEnr(O);
	until readkey=chr(27);
	writeln;
	writeln('fin de frogramme');
	readln;
End.