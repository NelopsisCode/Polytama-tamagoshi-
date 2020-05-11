					README
----------------------------------------------------------------------------------------

Groupe : Polytama-Tamagotchi
Membres : Thomas PISCIONE (p1808121), Mathias FLAGEY (p1801888), Catherine VANDEN HENDE (p1803635)

Dans le cadre de l'UE LIFAP4 et comme projet de fin de semestre, nous avons réalisé un jeu, de la conception à la programmation, avec l'aide de nos enseignants.

Langage de code : C++
IDE utilsées : NetBeans, Visual Studio Code, SublimeText
Bibliothèques utilisées : SDL pour la version graphique et Ncurses pour la version texte

	---------------
	Pour compiler :
	---------------
Commandes : cd.../polytama puis 

Sous Linux : make
Sous Windows : mingw32-make (avec mingw32 comme compilateur par défaut et en ayant modifier les variables sytemes en ajoutant C:\Program Files(x86)\CodeBlocks\MinGW\bin  dans le path)

	---------------
	Pour exécuter : 
	---------------
Commandes : cd.../polytama puis

Sous Linux : 
version texte : ./bin/polytama_txt
version graphique : ./bin/polytama_sdl

Sous Windows : 
version texte : bin/polytama_txt.exe
version graphique : bin/polytama_txt.sdl ou (pour la première exécution) aller dans le dossier /bin, créer un raccourci pour polytama_exe dans polytama en modifiant le démarrage dans les propriétés du raccourci (supprimer /bin) puis lancer le raccourci

Seule la version graphique est complètement fonctionnelle.

	---------------------------------------
	Pour générer la documentation de code :
	---------------------------------------
Dépendance : Doxygen
Commande : cd.../polytama puis doxygen doc/polytama.doxy

Pour l'ouvrir : .../polytama/doc/html/index.html


	---------------------------
	Le jeu et ses fichiers :
	---------------------------
Voici la composition du jeu Polytama.

Dans le dossier src/Core, on retrouve les classes du noyau du module :

Bar : Concerne les jauges (création, récuperation leur valeur, manipulation, ...)
Item : Concerne les objets 
Clothes : Concerne les vêtements, hérités d'Item
Consommable : Concerne la nourriture, hérités d'Item
InventoryClothes : Concerne l'inventaire de vêtements
InventoryConsommable : Concerne l'inventaire de nourriture
Mini_Game : Concerne les mini-jeux et leur récompense
Hanged : Concerne le pendu
Memory : Concerne le memory
Tictactoe : Concerne le morpion
Polytama : Concerne le polytama et la création de sa vie à l'aide des classes précédentes

Fichier de test régression : testPolytama.cpp 

Dans le dossier src/Sdl concernant l'adaptation graphique, on retrouve :

HangedSDL : Adaptation graphique du pendu (Affichage,..)
MemorySDL : Adaptation graphique du memory
TictactoeSDL : Adaptation graphique du Tictactoe
GameSDL : Adaptation graphique du polytama ainsi que mise en place des fonctions d'affichages des autres classes 

Fichier main : mainSDL.cpp 

Dans le dossier src/Txt concernant l'adaptation texte, on retrouve : 

GameTxt : Adaptation texte du polytama ainsi que mise en place des fonctions d'affichages des autres classes 
TictactoeTxt : Adaptation texte du Tictactoe

Fichier main : MainTxt.cpp 

Dans le dossier extern, on retrouve les librairies permettant de faire compiler la version texte et la version graphique sous Windows.

Dans le fichier data, on retrouve les polices d'écriture, les sons, les fichiers de sauvegarde et les images.

Dans le fichier doc, on retrouve une video de présentation, un diagramme des classes ainsi que le fichier de génération de la documentation.

Dans le fichier bin, on retoruve les exécutables, une fois la compilation faite, ainsi que les bibliothèques de lien dynamique (.dll) pour Ncurses et SDL.

	------------------------
	Fonctionnalités du jeu :
	------------------------

Le jeu Polytama est un jeu type tamagotchi. Le joueur s'occupe d'un petit être en lui donnant à manger, à boire, en jouant avec lui ou bien en l'habillant.

Lorsque le joueur lance le jeu, il doit choisir entre "Créer une nouvelle partie" ou "Continuer l'ancienne partie". 
S'il choisit de créer une nouvelle partie, l'ancienne partie sauvegardée est supprimée. 
Il peut alors choisir un nom pour son polytama,  l'habiller avec les vêtements de base et le nourrir avec les aliments de base, cette dernière action affecte les jauges de faim, soif, propreté et joie.
S'il veut gagner plus d'objets, il peut jouer au memory, au pendu ou bien au morpion. 
Il peut aussi visualiser ses inventaires de nourriture et de vêtements. 
La musique du jeu peut être coupée, baisée ou augmentée en fonction de son bon vouloir. 
En cliquant sur le nombril du polytama, il dab et cela affecte sa joie et sa propreté. 
Le joueur peut lui faire prendre un bain en cliquant sur l'icone brosse, cela affecte sa propreté. 
Si une des jauges du polytama est à 0, sa santé baisse. Si sa santé atteint 0, le polytama meurt. 
Il peut ressuciter et perd alors tous les objets non basiques de ses inventaires. 
Lorsque le joueur quitte le jeu, sa partie est sauvegardée et il peut y retourner en cliquant sur "Continuer l'ancienne partie".
