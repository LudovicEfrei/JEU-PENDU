# Pendu
Jeu du pendu réalisé en suivant le cours "Apprenez à programmer en C !" sur le site Open Classrooms
[https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c](url)

Le but est de deviner le mot secret en 10 coups. Pour la V0 le mot est prédéfini, et a chaque manche l'utilisateur propose une lettre. 
Cette lettre va être comparé avec le mot et sera révélée si elle est présente dans le mot. Si toutes les lettres sont révélés la partie est remportée.

V1 
- Ajout d'un fichier "Dictionnaire" dans lequel le programme pioche un mot au hasard pour ensuite le faire deviner. 

Une fonction va compter le nombre de mots dans le fichiers, en comptant les \n.
Ensuite une autre fonction va tirer au hasard un mot, avec un rand entre 1 et le nombre de mots.
On compte le nombre de lettre dans le mot séléctionné
L'allocation dynamique va nous permettre de générer 2 tableaux de la taille du mot à deviner.
Une fois les 2 tableaux générer on recupère les lettre du mots tiré au hasard dans le premier tableaux (via pointeur)
et on remplit le second de caractère mystère '*'
Ensuite le programme fonctionne comme lors de la V0.
