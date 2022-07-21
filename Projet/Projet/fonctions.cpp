#include "fonction.hpp"

using namespace std;

string toBinary (int n)
{
  string r;
  while (n != 0)
    {
      r = (n % 2 == 0 ? "0" : "1") + r;
      n /= 2;
    }
  return r;
}

string convert(int x){
  string rev = "";
  string biny = toBinary (x);
  string z = "";
  string revbin = "";
  string res = "";
  if (x<0){
    for(int i = 0; i < biny.length (); i++){
        if (biny[i] == '0'){
          revbin += "1";
        }
        else{
          revbin += "0";
        }
    }
    for(int j = 0; j < 32 - revbin.length (); j++){
        res += '1';
    }
    res += revbin;
    for(int i = res.length()-1; i > 0; i--){
        if(res[i] == '1'){
            res[i] = '0';
        }
        else{
            res[i] = '1';
            i= 0;
        }
    }
  }
  else{
    for (int j = 0; j < 32 - biny.length (); j++){
        res += '0';
    }
    res += biny;
  }
  return res;
}

vector<vector<int>> pointToVector(std::vector<Pair> liste_point){
    std::vector<std::vector<int>> liste_vecteur;
    std::vector<int> point;
    for(int x = 0; x < (liste_point.size() - 1) ; x++){
        point.clear();
        point.push_back((liste_point.at(x+1).first - liste_point.at(x).first));
        point.push_back((liste_point.at(x+1).second - liste_point.at(x).second));
        liste_vecteur.push_back(point);
    }
    return liste_vecteur;
}

int distance(int Xa, int Ya, int Xb, int Yb){
    int result = sqrt(pow((Xa - Xb),2) + pow((Ya - Yb),2));
    return result;
}

vector<int> CheckArrivee(png::image<png::rgb_pixel> image, auto options){
    // cette fonction permet de chercher tous les pixels sur une image qui sont de la couleur de l'arrivée (couleur donnée en option)
    vector<int> couleur_arrivee = toml::find<std::vector<int>>(options,"couleur_arrivee");;
    vector<std::vector<int>*> Zone_Arrivee;

    for (png::uint_32 y = 0; y < image.get_height(); ++y){
      for (png::uint_32 x = 0; x < image.get_width(); ++x){
        if (image[y][x].red == couleur_arrivee.at(0) && image[y][x].green == couleur_arrivee.at(1) && image[y][x].blue == couleur_arrivee.at(2)){
          //std::cout<<"Arrivée en : ["<< x << ";" << y << "]"<<std::endl;
          Zone_Arrivee.push_back(new vector<int> {(int) x,(int) y});
        }
      }
    }

    if (Zone_Arrivee.size() == 0){
        // cas où on ne trouve aucun pixel de la bonne couleur
      return *(new vector<int>{-1,-1});
    }

    // vu que plusieurs points peuvent correspondre à l'arrivée, on choisit de renvoyer un milieu approximatif à cette zone d'arrivée
    return *(Zone_Arrivee.at(((Zone_Arrivee.size())/2)));
}

  /* Fonction pour trouver le point de depart */
std::vector<int> CheckDepart(png::image<png::rgb_pixel> image, auto options){
    const auto d = toml::find(options, "depart");
    int d1 = toml::find<int>(d,"y");
    int d2 = toml::find<int>(d,"x");

    for (png::uint_32 y = 0; y < image.get_height(); ++y){
      for (png::uint_32 x = 0; x < image.get_width(); ++x){
        if((int) y == d1 && (int) x == d2){
          vector<int>* v = new vector<int> {(int) x, (int) y};
          // std::cout<<"Départ en : ["<< x << ";" << y << "]"<<std::endl;
          return *v;
        }
      }
    }
    vector<int>* e = new std::vector<int>{-1,1};
    return *e;
}
 
// Cette fonction teste si une cellule a des coordonnees coherentes
bool isValid(int row, int col, int ROW, int COL)
{

    return (row >= 0) && (row < ROW) && (col >= 0)
           && (col < COL);
}

bool isPathable(int** grid, int x0, int y0, int x1, int y1){
    // cette fonction permet de tester si une trajectoire entre deux points traverse un pixel noir
    int dx, dy, p, x, y;
    // cout << " p1 : " << x0 << ";" << y0 << " || " << "p2 : " << x1 << ";" << y1 << endl;
    dx=x1-x0;
    dy=y1-y0;
    x=x0;
    y=y0;
    p=2*dy-dx;
    while(x<x1){
        if(p>=0){
            if(grid[x][y] == 1){
                return false;
            }
            y=y+1;
            p=p+2*dy-2*dx;
        }else{
            if(grid[x][y] == 1){
                return false;
            }
            p=p+2*dy;
        }
        x=x+1;
    }
    return true;
}


bool is_notBlack(Pair point, png::image<png::rgb_pixel> image){
    // cette fonction permet de tester si un point est entouré de pixels noirs
  int k = 0;
  for(int x=(point.first)-1; x<= (point.first)+1; x+=2){
    for(int y=(point.second)-1; y<= (point.second)+1; y+=2){
      if(image[y][x].red < 15 && image[y][x].blue < 15 && image[y][x].green < 15){
        return false;
      }
    }
  }

  return true;
}
 
// Cette fonction teste si le pixel teste est valide
bool isUnBlocked(int** grid, int row, int col)
{
  //cout << "Point: " << grid[row][col] << endl; 
    if (grid[row][col] != 1){
      return true;
    }
    else{
        return false;}
}
 
// Cette fonction teste si le pixel est un point de la zone de destination
bool isDestination(int row, int col, Pair dest)
{
    if (row == dest.first && col == dest.second)
        return (true);
    else
        return (false);
}
 
// Cette fonction calcule le cout de la trajectoire sur chaque pixel
double calculateHValue(int row, int col, Pair dest)
{
    // Return using the distance formula
    return ((double)sqrt(
        (row - dest.first) * (row - dest.first)
        + (col - dest.second) * (col - dest.second)));
}
 
// Cette fonction trace le chemin du depart a l'arrivee
stack<Pair> tracePath(cell** cellDetails, Pair dest)
{
    int row = dest.first;
    int col = dest.second;
 
    stack<Pair> Path;
 
    while (!(cellDetails[row][col].parent_i == row
             && cellDetails[row][col].parent_j == col)) {
        Path.push(make_pair(row, col));
        int temp_row = cellDetails[row][col].parent_i;
        int temp_col = cellDetails[row][col].parent_j;
        row = temp_row;
        col = temp_col;
    }
 
    Path.push(make_pair(row, col));
 
    return Path;
}
 

stack<Pair> aStarSearch(int** grid, Pair src, Pair dest, int ROW, int COL, png::image<png::rgb_pixel> image)
//cette fonction permet de calculer une trajectoire entre deux points. Elle nous renvoie une pile de points.
{
    // Si le pixel de depart a des coordonnees invalides
    if (isValid(src.first, src.second, ROW, COL) == false) {
        throw std::invalid_argument("Depart invalide\n");
    }
 
    // Si le pixel de destination a des coordonnees invalides
    if (isValid(dest.first, dest.second, ROW, COL) == false) {
      cout << " x : " << dest.second << "XMAX : " << COL << "Y : " << dest.first << "YMAX : " << ROW << endl;
        throw std::invalid_argument("Destination invalide\n");
    }
 
    // Si le pixel de depart ou de destination est inpraticable
    if (isUnBlocked(grid, src.first, src.second) == false || isUnBlocked(grid, dest.first, dest.second) == false) {
        throw std::invalid_argument("La destination ou le depart sont des obstacles\n");
    }
 
    // Si la cellule de depart et de destination ont les memes coordonnees
    if (isDestination(src.first, src.second, dest)
        == true) {
        throw std::invalid_argument("Nous sommes deja a la destination\n");
    }
 

    //Creation d'un tableau de booleans a deux dimentions dont toutes les valeurs sont initialisees a false 
    //afin de savoir quel pixel a ete inclu dans le chemin
    bool closedList[ROW][COL];
    memset(closedList, false, sizeof(closedList));
 
    //On declare un tableau de deux dimentions qui permettra de stocker les cellules
    cell** cellDetails = new cell* [ROW];
    for(int i = 0; i < ROW; ++i){
      cellDetails[i] = new cell[COL];
    }

 
    int i, j;
 
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            cellDetails[i][j].f = FLT_MAX;
            cellDetails[i][j].g = FLT_MAX;
            cellDetails[i][j].h = FLT_MAX;
            cellDetails[i][j].parent_i = -1;
            cellDetails[i][j].parent_j = -1;
        }
    }
 
    // Initialisation des valeurs de la cellule de depart
    i = src.first, j = src.second;
    cellDetails[i][j].f = 0.0;
    cellDetails[i][j].g = 0.0;
    cellDetails[i][j].h = 0.0;
    cellDetails[i][j].parent_i = i;
    cellDetails[i][j].parent_j = j;
 
    
    //on creee une liste qui contiendra le cout de deplacement, et les coordonnees des cellules
    set<pPair> openList;
 
    // On integre la cellule initiale dans la liste et on initialise son cout (f) a 0
    openList.insert(make_pair(0.0, make_pair(i, j)));
 
    bool foundDest = false;
 
    while (!openList.empty()) {
        pPair p = *openList.begin();
 
        openList.erase(openList.begin());
 
        // On met la valeur de cette cellule a true dans la liste de booleans
        i = p.second.first;
        j = p.second.second;
        closedList[i][j] = true;
 
        // On stocke maintenant les valeurs g, h et f des 8 successeurs de cette cellule
        // (celles qui se situent autour ce la cellule en cours de traitement)
        double gNew, hNew, fNew;
 
        //----------- 1er Successeur (nord) ------------
 
        // On verifie d'abord que la cellule ai des coordonnees valides
        if (isValid(i - 1, j, ROW, COL) == true) {
            // On verifie ensuite si ce successeur fais partie de la destination
            if (isDestination(i - 1, j, dest) == true) {
                // On definit le parent de la cellule destination
                cellDetails[i - 1][j].parent_i = i;
                cellDetails[i - 1][j].parent_j = j;
                printf("Destination trouvee\n");
                foundDest = true;
                return tracePath(cellDetails, dest);
            }
            // Si ce successeur est deja dans la liste de booleans, ou si il est obstrue, l'ignorer.
            else if (closedList[i - 1][j] == false
                     && isUnBlocked(grid, i - 1, j)
                            == true) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i - 1, j, dest);
                fNew = gNew + hNew;
 
                // Si cette cellule n'est pas dans la openlist, l'y ajouter,
                // en faisant la cellule actuelle son parent et en renseignant son cout (f, g et h)
                //                          ou
                // Si cette cellule figure dans la liste, on verifie le chemin qui y mene depuis
                // cette cellule est moins cher en utilisant la variable f pour reference
                if (cellDetails[i - 1][j].f == FLT_MAX
                    || cellDetails[i - 1][j].f > fNew) {
                    openList.insert(make_pair(
                        fNew, make_pair(i - 1, j)));
 
                    // Update the details of this cell
                    cellDetails[i - 1][j].f = fNew;
                    cellDetails[i - 1][j].g = gNew;
                    cellDetails[i - 1][j].h = hNew;
                    cellDetails[i - 1][j].parent_i = i;
                    cellDetails[i - 1][j].parent_j = j;
                }
            }
        }
 
        //----------- 2eme Successeur (sud) ------------
 
        if (isValid(i + 1, j, ROW, COL) == true) {
            if (isDestination(i + 1, j, dest) == true) {
                cellDetails[i + 1][j].parent_i = i;
                cellDetails[i + 1][j].parent_j = j;
                printf("Destination trouvee\n");
                foundDest = true;
                return tracePath(cellDetails, dest);
            }
            else if (closedList[i + 1][j] == false
                     && isUnBlocked(grid, i + 1, j)
                            == true) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i + 1, j, dest);
                fNew = gNew + hNew;
 
                if (cellDetails[i + 1][j].f == FLT_MAX
                    || cellDetails[i + 1][j].f > fNew) {
                    openList.insert(make_pair(
                        fNew, make_pair(i + 1, j)));
                    cellDetails[i + 1][j].f = fNew;
                    cellDetails[i + 1][j].g = gNew;
                    cellDetails[i + 1][j].h = hNew;
                    cellDetails[i + 1][j].parent_i = i;
                    cellDetails[i + 1][j].parent_j = j;
                }
            }
        }
 
        //----------- 3eme Successeur (est) -----------ne
        if (isValid(i, j + 1, ROW, COL) == true) {
            if (isDestination(i, j + 1, dest) == true) {
                cellDetails[i][j + 1].parent_i = i;
                cellDetails[i][j + 1].parent_j = j;
                printf("Destination trouvee\n");
                foundDest = true;
                return tracePath(cellDetails, dest);
            }
 
            else if (closedList[i][j + 1] == false
                     && isUnBlocked(grid, i, j + 1)
                            == true) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i, j + 1, dest);
                fNew = gNew + hNew;
 
                if (cellDetails[i][j + 1].f == FLT_MAX
                    || cellDetails[i][j + 1].f > fNew) {
                    openList.insert(make_pair(
                        fNew, make_pair(i, j + 1)));
 
                    cellDetails[i][j + 1].f = fNew;
                    cellDetails[i][j + 1].g = gNew;
                    cellDetails[i][j + 1].h = hNew;
                    cellDetails[i][j + 1].parent_i = i;
                    cellDetails[i][j + 1].parent_j = j;
                }
            }
        }
 
        //----------- 4eme Successeur (ouest) ------------
 
        if (isValid(i, j - 1, ROW, COL) == true) {
            if (isDestination(i, j - 1, dest) == true) {
                cellDetails[i][j - 1].parent_i = i;
                cellDetails[i][j - 1].parent_j = j;
                printf("Destination trouvee\n");
                foundDest = true;
                return tracePath(cellDetails, dest);
            }
 
            else if (closedList[i][j - 1] == false
                     && isUnBlocked(grid, i, j - 1)
                            == true) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i, j - 1, dest);
                fNew = gNew + hNew;
 
                if (cellDetails[i][j - 1].f == FLT_MAX
                    || cellDetails[i][j - 1].f > fNew) {
                    openList.insert(make_pair(
                        fNew, make_pair(i, j - 1)));

                    cellDetails[i][j - 1].f = fNew;
                    cellDetails[i][j - 1].g = gNew;
                    cellDetails[i][j - 1].h = hNew;
                    cellDetails[i][j - 1].parent_i = i;
                    cellDetails[i][j - 1].parent_j = j;
                }
            }
        }
 
        //----------- 5eme Successeur (nord-est) ------------
 
        if (isValid(i - 1, j + 1, ROW, COL) == true) {
            if (isDestination(i - 1, j + 1, dest) == true) {
                cellDetails[i - 1][j + 1].parent_i = i;
                cellDetails[i - 1][j + 1].parent_j = j;
                printf("Destination trouvee\n");
                foundDest = true;
                return tracePath(cellDetails, dest);
            }
 
            else if (closedList[i - 1][j + 1] == false
                     && isUnBlocked(grid, i - 1, j + 1)
                            == true) {
                gNew = cellDetails[i][j].g + 1.414;
                hNew = calculateHValue(i - 1, j + 1, dest);
                fNew = gNew + hNew;
 
                if (cellDetails[i - 1][j + 1].f == FLT_MAX
                    || cellDetails[i - 1][j + 1].f > fNew) {
                    openList.insert(make_pair(
                        fNew, make_pair(i - 1, j + 1)));
 
                    cellDetails[i - 1][j + 1].f = fNew;
                    cellDetails[i - 1][j + 1].g = gNew;
                    cellDetails[i - 1][j + 1].h = hNew;
                    cellDetails[i - 1][j + 1].parent_i = i;
                    cellDetails[i - 1][j + 1].parent_j = j;
                }
            }
        }
 
        //----------- 6eme Successeur (nord-ouest) ------------
 
        if (isValid(i - 1, j - 1, ROW, COL) == true) {
            if (isDestination(i - 1, j - 1, dest) == true) {
                cellDetails[i - 1][j - 1].parent_i = i;
                cellDetails[i - 1][j - 1].parent_j = j;
                printf("Destination trouvee\n");
                foundDest = true;
                return tracePath(cellDetails, dest);
            }
 

            else if (closedList[i - 1][j - 1] == false
                     && isUnBlocked(grid, i - 1, j - 1)
                            == true) {
                gNew = cellDetails[i][j].g + 1.414;
                hNew = calculateHValue(i - 1, j - 1, dest);
                fNew = gNew + hNew;
 
                if (cellDetails[i - 1][j - 1].f == FLT_MAX
                    || cellDetails[i - 1][j - 1].f > fNew) {
                    openList.insert(make_pair(
                        fNew, make_pair(i - 1, j - 1)));
                    cellDetails[i - 1][j - 1].f = fNew;
                    cellDetails[i - 1][j - 1].g = gNew;
                    cellDetails[i - 1][j - 1].h = hNew;
                    cellDetails[i - 1][j - 1].parent_i = i;
                    cellDetails[i - 1][j - 1].parent_j = j;
                }
            }
        }
 
        //----------- 7eme Successeur (sud-est) ------------
 
        if (isValid(i + 1, j + 1, ROW, COL) == true) {
            if (isDestination(i + 1, j + 1, dest) == true) {
                cellDetails[i + 1][j + 1].parent_i = i;
                cellDetails[i + 1][j + 1].parent_j = j;
                printf("Destination trouvee\n");
                foundDest = true;
                return tracePath(cellDetails, dest);
            }
 

            else if (closedList[i + 1][j + 1] == false
                     && isUnBlocked(grid, i + 1, j + 1)
                            == true) {
                gNew = cellDetails[i][j].g + 1.414;
                hNew = calculateHValue(i + 1, j + 1, dest);
                fNew = gNew + hNew;
 
                if (cellDetails[i + 1][j + 1].f == FLT_MAX
                    || cellDetails[i + 1][j + 1].f > fNew) {
                    openList.insert(make_pair(
                        fNew, make_pair(i + 1, j + 1)));
 
                    cellDetails[i + 1][j + 1].f = fNew;
                    cellDetails[i + 1][j + 1].g = gNew;
                    cellDetails[i + 1][j + 1].h = hNew;
                    cellDetails[i + 1][j + 1].parent_i = i;
                    cellDetails[i + 1][j + 1].parent_j = j;
                }
            }
        }

        //----------- 8ème Successeur (sud-ouest) ------------
 
        if (isValid(i + 1, j - 1, ROW, COL) == true) {
            if (isDestination(i + 1, j - 1, dest) == true) {
                cellDetails[i + 1][j - 1].parent_i = i;
                cellDetails[i + 1][j - 1].parent_j = j;
                printf("Destination trouvee\n");
                foundDest = true;
                return tracePath(cellDetails, dest);
            }
 

            else if (closedList[i + 1][j - 1] == false
                     && isUnBlocked(grid, i + 1, j - 1)
                            == true) {
                gNew = cellDetails[i][j].g + 1.414;
                hNew = calculateHValue(i + 1, j - 1, dest);
                fNew = gNew + hNew;
 
                if (cellDetails[i + 1][j - 1].f == FLT_MAX
                    || cellDetails[i + 1][j - 1].f > fNew) {
                    openList.insert(make_pair(
                        fNew, make_pair(i + 1, j - 1)));
 
                    cellDetails[i + 1][j - 1].f = fNew;
                    cellDetails[i + 1][j - 1].g = gNew;
                    cellDetails[i + 1][j - 1].h = hNew;
                    cellDetails[i + 1][j - 1].parent_i = i;
                    cellDetails[i + 1][j - 1].parent_j = j;
                }
            }
        }
    }
 
    if (foundDest == false)
        throw std::invalid_argument("Destination introuvable\n");
}


/*===============================================================================*/

vector<Pair> Optimizatron(png::image<png::rgb_pixel> image, int** map, stack<Pair> trajectoire, auto options){
    // cette fonction va nous permettre d'affiner la trajectoire calculée par A*, afin d'avoir le moins de points possibles.
  vector<Pair> tab_traj = * new vector<Pair>;
  int acc_max =  toml::find<int>(options, "acc_max");
  vector<Pair> new_traj = * new vector<Pair>;

  vector<int> couleur_arrivee = toml::find<std::vector<int>>(options,"couleur_arrivee");;

  // on vide la pile et on stock dans un vecteur

  while(!trajectoire.empty()){
      Pair x = trajectoire.top();
      trajectoire.pop();
      tab_traj.push_back(x);
  }

  // optimisation de la trajectoire

  int iterator = 0;
  Pair point_potentiel = tab_traj.at(0); // ceci défini notre point atteignable le plus proche de l'arrivée (par défaut c'est le point de départ)
  bool stocked = false;

  while (iterator < tab_traj.size()){

        // on ajoute le dernier point retenu comme étant le choix le plus optimal par l'itération précédente (permet aussi d'initialiser avec le point de départ). On appellera ce point le point origine.
        new_traj.push_back(point_potentiel);
        stocked = true; //on indique au programme que le point actuellement stocké est déjà dans la trajectoire et qu'il faut donc l'ignorer lors de la première instanciation.

        int inertie = 0;

        if(new_traj.size() >= 2 ){
            //on calcule l'inertie actuelle si notre vecteur comporte au moins deux points (permet de savoir à quelle vitesse est arrivé notre kart sur le dernier point)
          inertie = distance(new_traj.back().first, new_traj.back().second, new_traj.at((new_traj.size())-2).first, new_traj.at((new_traj.size())-2).second);
        }

        int increment = 1;
        int min = 1; // on définit la distance minimale que le kart doit parcourir pour aller au prochain point

        if(inertie > acc_max){
            // on calcule le minimal en se basant sur le freinage maximal du kart
            min = inertie - acc_max;
        }

        int rayon = acc_max;

        for(int i = 1; i < tab_traj.size(); i++){ // on regarde tous les points retenu par notre trajectoire qui sont dans la zone d'accélération de notre kart dans le but de prendre le plus proche de l'arrivée et de virer tous les autres
          if(i+inertie+iterator < tab_traj.size()){
            if((pow(((tab_traj.at(iterator+i).first)-(tab_traj.at(iterator)).first),2) + pow(((tab_traj.at(iterator+i).second)-(tab_traj.at(iterator)).second),2)) <= pow(rayon,2)) {
              // on détermine le nombre de points atteignables puis on choisi celui qui est le plus éloigné de l'origine et dont la trajectoire ne traverse pas de pixel noir.
              if(distance(tab_traj.at(iterator).first, tab_traj.at(iterator).second, tab_traj.at(iterator+i).first, tab_traj.at(iterator+i).second) > distance(tab_traj.at(iterator).first, tab_traj.at(iterator).second, point_potentiel.first, point_potentiel.second) && isPathable(map, tab_traj.at(iterator+i).first, tab_traj.at(iterator+i).second, tab_traj.at(iterator).first, tab_traj.at(iterator).second) && isPathable(map, tab_traj.at(iterator).first, tab_traj.at(iterator).second, tab_traj.at(iterator+i).first, tab_traj.at(iterator+i).second)){
                point_potentiel.first = tab_traj.at(iterator+i).first;
                point_potentiel.second = tab_traj.at(iterator+i).second;
                increment = i;
              }
              else if(stocked = true && isPathable(map, tab_traj.at(iterator+i).first, tab_traj.at(iterator+i).second, tab_traj.at(iterator).first, tab_traj.at(iterator).second) && isPathable(map, tab_traj.at(iterator).first, tab_traj.at(iterator).second, tab_traj.at(iterator+i).first, tab_traj.at(iterator+i).second)){
                point_potentiel.first = tab_traj.at(iterator+i).first;
                point_potentiel.second = tab_traj.at(iterator+i).second;
                increment = i;
                stocked = false; 
              }
            }
          }
        }

        iterator += increment;

        if (image[(new_traj.back()).second][(new_traj.back()).first].red == couleur_arrivee.at(0) && image[(new_traj.back()).second][(new_traj.back()).first].green == couleur_arrivee.at(1) && image[(new_traj.back()).second][(new_traj.back()).first].blue == couleur_arrivee.at(2)){
            // si le dernier point atteint correspond à un point d'arrivée, on arrête le traitement car sa ne sert à rien d'aller plus loin.
            break;
        }
    }


  for (int i =0; i<new_traj.size(); i++){
    // on dessine les points sur une image
    image[new_traj.at(i).second][new_traj.at(i).first] = png::rgb_pixel(255,125,0);
  }

  image.write("rgb.png");
  return new_traj; // on retourne le nouveau vector trajectoire, pour qu'il puisse être convertis et envoyé au serveur.
}


int** MakeGrid(png::image<png::rgb_pixel> image){
    // cette fonction permet de transformer une image en une matrice de collisions (0 indique que c'est traversable, 1 indique un obstacle)
  int** grid = new int*[(int) image.get_width()];
  for(int i = 0; i < (int) image.get_width(); ++i){
    grid[i] = new int[(int) image.get_height()];
  }

  for (png::uint_32 y = 0; y < image.get_height(); ++y){
      for (png::uint_32 x = 0; x < image.get_width(); ++x){
        if(image[y][x].red < 7 && image[y][x].blue < 7 && image[y][x].green < 7){ // les bordures n'étant pas toutes au même nuances RGB, on choisit d'implémenter une tolérance de 7.
          // cout << "y:" << y << "x:" << x << endl;
          grid[x][y] = 1;
        }

        else{
          // cout << "y:" << y << "x:" << x << endl;
          grid[x][y] = 0;
        }
      }
  }

  return grid;
}

vector<Pair> findTraj(png::image<png::rgb_pixel> image, auto options){
  //on récupère les dimensions de l'image
  int ROW = image.get_width();
  int COL = image.get_height();
  //on transforme l'image en matrice collision
  int** map = MakeGrid(image);
  // on récupère le départ ainsi que l'arrivée, puis on en fait des paires.
  vector<int> depart = CheckDepart(image, options);
  vector<int> arrivee = CheckArrivee(image, options);
  Pair src = make_pair(depart.at(0), depart.at(1));
  Pair dest = make_pair(arrivee.at(0), arrivee.at(1));
  //on appelle l'algorithme de calcul de trajectoire
  stack<Pair> traj = aStarSearch(map, src, dest, ROW, COL, image);
  //on optimise la trajectoire obtenue
  vector<Pair> opti_traj = Optimizatron(image, map, traj, options);
  return opti_traj;
}