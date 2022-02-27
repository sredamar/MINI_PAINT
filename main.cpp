#include "painter.h"
int main() {
    int bigwidth, bigheight, colbg;
    char chbg;
    string filename, issave, inputline, s, line, strcolbg;
    bool save = false, ok = true;
    getline(cin, inputline);
    vector<string> inputlinearr = strtoarr(inputline);
    if (inputlinearr.size() < 1 || inputlinearr.size() > 2) {
        error("Error: wrong number of arguments");
        return 0;}
    else if (inputlinearr.size() == 1) filename = inputlinearr[0];
    else if (inputlinearr.size() == 2) {
        filename = inputlinearr[0];
        issave = inputlinearr[1];
        if (issave=="--save") save = true;
        else {
            error("Error: wrong parameter");
            return 0;}}
    if (ok) {
        if (slicer(filename, len(filename) - 4, len(filename)) != ".txt") {
            error("Error: Operation file has an incorrect extension");
            return 0;}
        ifstream f(filename);
        if (!f.good()) {
            error("Error: name file");
            return 0;}}
    ifstream inmyfile (filename);
    if (!inmyfile.is_open()){
        error("Error: Operation file corrupted");
        return 0;}
    if (ok && isOk(filename)) {
    inmyfile.is_open();
    inmyfile >> bigwidth >> bigheight >> chbg >> strcolbg;
    if (bigwidth > 300 || bigheight > 300) {
            error("Error: wrong background parameters");
            return 0;}
    if (strcolbg=="RGB_R") colbg=4;
    if (strcolbg=="RGB_G") colbg=10;
    if (strcolbg=="RGB_B") colbg=11;
    vector <char> arch;
    vector <int> arcol;
    float** m;
    m = new float*[1];
    int matlen=0;
    while (!inmyfile.eof()) {
        inmyfile >> s;
        m[matlen] = new float[5];
        matlen++;
        char f = s[0];
        m[matlen-1][0]=find("rRcCL",s);
        if (f=='r' || f=='R' || f=='L') {
            for (int j=1;j<5;j++)
                inmyfile >> m[matlen-1][j];
          char che;
          inmyfile >> che;
          if (che==chbg) {
              cout << "Enter a different character for the " << f << " object: ";
              cin >> che;
              while (che==chbg) {
                  cout << "\nA different one, please: ";
                  cin >> che;
              }
              cout << "\n";
          }
          arch.push_back(che);
        }
        if (f=='c'|| f=='C') {
            for (int j=1;j<4;j++)
                inmyfile>>m[matlen-1][j];
            char che;
            inmyfile >> che;
                      if (che==chbg) {
              cout << "Enter a different character for the " << f << " object: ";
              cin >> che;
              while (che==chbg) {
                  cout << "\nA different one, please: ";
                  cin >> che;
              }
              cout << "\n";
          }
            arch.push_back(che);}
        string strcol;
        inmyfile >> strcol;
        if (strcol=="RGB_R") arcol.push_back(4);
        if (strcol=="RGB_G") arcol.push_back(10);
        if (strcol=="RGB_B") arcol.push_back(11);
    }
    inmyfile.close();

    ofstream myfile;
    if (save) myfile.open ("result_operation_file.txt");
    for (int _y=0;_y<bigheight/2;_y++) {
        float y;
        y = _y*2;
        for (int x=0;x<bigwidth;x++) {
            char pix;
            int col;
            pix = chbg;
            col = colbg;
            int i=matlen-1;
            bool end;
            end=false;
            while(i>-1 && !end) {
                if ((m[i][0]==0 && (mabs(m[i][1],x)<1 || mabs(x,m[i][1]+m[i][3]-1)<1 || mabs(m[i][2],y)<1 || mabs(y,m[i][2]+m[i][4]-1)<1) && m[i][1] <= x && x <= m[i][1]+m[i][3]-1 && m[i][2] <= y && y <= m[i][2]+m[i][4]-1) || (m[i][0]==1 && m[i][1] <= x && x <= m[i][1]+m[i][3]-1 && m[i][2] <= y && y <= m[i][2]+m[i][4]-1) || (m[i][0]==2 && isincircleborder(m[i][1],m[i][2],m[i][3],x,y)) || (m[i][0]==3 && isincircle(m[i][1],m[i][2],m[i][3],x,y)) || (m[i][0]==4 && isinline(m[i][1],m[i][2],m[i][3],m[i][4],x,y) && mymin(m[i][1],m[i][3]) <= x && x <= mymax(m[i][1],m[i][3]) && mymin(m[i][2],m[i][4]) <= y && y <= mymax(m[i][2],m[i][4]))) {
                    pix = arch[i];
                    col = arcol[i];
                    end = true;}
                i--;
            }
            if (save) myfile << pix;
            SetColor(col, 0);
            cout << pix;
        }
        if (save) myfile << "\n";
        cout << "\n";
    }
    if (save) myfile.close();
    SetColor(7, 0);}
    return 0;}
