#ft_ls

**Introduction:**

Recoder la commande ls et certaines de ses options vous permettra de découvrir
comment intéragir avec le système de fichiers depuis un programme en C. Après tout,
vous savez déja comment ouvrir, lire, écrire et fermer un fichier. Mais qu’en est-il des
répertoires ? Des fichiers spéciaux ? Des droits, des dates ou de la taille des fichiers ?

**Objectifis:**

Le projet ft_ls vous ouvre la voie de l’arc Unix du graph de projets. Vous allez
pour la première fois être confrontés à des fonctions de la libc vous permettant autre
chose que lire ou écrire sur un file descriptor (pour caricaturer). Vous allez découvrir un
sous ensemble de fonctions de l’API de votre système d’exploitation et les structures de
données associées, ainsi que la gestion des allocations mémoires qui vont avec ces données.
ft_ls est également une excellente opportunité de réflechir à la structure de votre
code avant de vous jeter à corps perdu dans l’écriture du code. La mauvaise réputation
de ft_ls est principalement répandue par des étudiants découvrant trop tard que leur
(manque de) design initial les empêche de terminer le projet sans refactoriser une immense
partie de leur code.
