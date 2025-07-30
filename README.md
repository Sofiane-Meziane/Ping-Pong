# Jeu de Ping Pong en C avec Raylib

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)

![Capture d'écran du jeu Ping Pong](https://raw.githubusercontent.com/Sofiane-Meziane/ping-pong/main/ping%20pong55.png)

## 🕹️ À propos du projet

Ce projet est un mini-jeu de **Ping Pong en 2D**, entièrement développé en langage **C** à l'aide de la bibliothèque graphique **Raylib**. Réalisé en première année d'études, ce projet a été une excellente opportunité de consolider les bases de la programmation procédurale, de la gestion des entrées clavier et du rendu graphique interactif.

Le gameplay est simple et réactif, opposant le joueur à un adversaire contrôlé par l'ordinateur.

---

## ✨ Fonctionnalités

* **Gameplay simple et réactif :** Contrôlez votre raquette avec les touches du clavier pour renvoyer la balle.
* **Adversaire IA :** L'adversaire est contrôlé par l'ordinateur et suit automatiquement la trajectoire de la balle en temps réel.
* **Gestion de la balle :** La balle a une vitesse dynamique et rebondit sur les raquettes et les bords de l'écran.
* **Détection des collisions :** Une détection précise des collisions entre la balle, les raquettes et les murs.
* **Système de score :** Le score est affiché et mis à jour en temps réel.

---

## 🛠️ Stack Technique

* **Langage :** C
* **Bibliothèque graphique :** Raylib pour le rendu 2D, la gestion des fenêtres et des événements.
* **Compilateur :** GCC (MinGW sur Windows)

---

## ⚙️ Installation et Lancement

Pour compiler et lancer ce projet, vous devez avoir un environnement de développement C et la bibliothèque Raylib installés.

### Pré-requis
* Un compilateur C (comme **GCC/MinGW**)
* La bibliothèque **Raylib** installée sur votre système.

### Étapes de compilation
1.  **Clonez le repository** sur votre machine :
    ```sh
    git clone [https://github.com/Sofiane-Meziane/ping-pong.git](https://github.com/Sofiane-Meziane/ping-pong.git)
    ```
2.  **Naviguez vers le dossier** du projet :
    ```sh
    cd ping-pong
    ```
3.  **Compilez le projet** en liant la bibliothèque Raylib. La commande peut varier légèrement selon votre système d'exploitation :

    * **Sur Windows (avec MinGW) :**
        ```sh
        gcc main.c -o pingpong.exe -I external/raylib/include -L external/raylib/lib -lraylib -lopengl32 -lgdi32 -lwinmm
        ```
    * **Sur Linux :**
        ```sh
        gcc main.c -o pingpong -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
        ```

4.  **Lancez le jeu** :
    ```sh
    # Sur Windows
    ./pingpong.exe

    # Sur Linux
    ./pingpong
    ```

> **Note :** Les commandes de compilation supposent que Raylib est correctement installé. Les chemins (`-I` et `-L`) peuvent nécessiter d'être adaptés en fonction de votre configuration.

---

## 📄 Licence

Distribué sous la licence MIT. Voir le fichier `LICENSE` pour plus d'informations.
