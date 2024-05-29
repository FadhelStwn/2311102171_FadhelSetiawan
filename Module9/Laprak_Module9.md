# <h1 align="center">Laporan Praktikum Modul 8 - Algoritma Searching</h1>
<p align="center">Fadhel Setiawan - 2311102171</p>

## Dasar Teori

### Pengertian Graph
Graf atau graph adalah struktur data yang digunakan untuk merepresentasikan hubungan antara objek dalam bentuk node atau vertex dan sambungan antara node tersebut dalam bentuk sisi atau edge. Graf terdiri dari simpul dan busur yang secara matematis dinyatakan sebagai :
</br>
G = (V, E)
</br>
Dimana G adalah Graph, V adalah simpul atau vertex dan E sebagai sisi atau edge.
Dapat digambarkan:

![alt text](<Screenshot 2024-05-29 182439.png>)
</br>
Graph dapat digunakan dalam berbagai aplikasi, seperti jaringan sosial, pemetaan jalan,
dan pemodelan data.

### Jenis-Jenis Graph

1. Undirected Graph</br>
![alt text](<Screenshot 2024-05-29 190515.png>)</br>
Pada undirected graph, simpul-simpulnya terhubung dengan edge yang sifatnya dua arah. Misalnya kita punya simpul 1 dan 2 yang saling terhubung, kita bisa menjelajah dari simpul 1 ke simpul 2, begitu juga sebaliknya.</br>

2. Directed Graph</br>
![alt text](<Screenshot 2024-05-29 185101.png>)</br>
Kebalikan dari undirected graph, pada graph jenis ini simpul-simpulnya terhubung oleh edge yang hanya bisa melakukan jelajah satu arah pada simpul yang ditunjuk. Sebagai contoh jika ada simpul A yang terhubung ke simpul B, namun arah panahnya menuju simpul B, maka kita hanya bisa melakukan jelajah (traversing) dari simpul A ke simpul B, dan tidak berlaku sebaliknya.</br>

3. Weighted Graph</br>
![alt text](<Screenshot 2024-05-29 185114.png>)</br>
Weighted graph adalah jenis graph yang cabangnya diberi label bobot berupa bilangan numerik. Pemberian label bobot pada edge biasanya digunakan untuk memudahkan algoritma dalam menyelesaikan masalah.</br>

4. Unweighted Graph</br>
![alt text](<Screenshot 2024-05-29 185101-1.png>)</br>
Berbeda dengan jenis sebelumnya, unweighted graph tidak memiliki properti bobot pada koneksinya. Graph ini hanya mempertimbangkan apakah dua node saling terhubung atau tidak.


### Tree

### Pengertian Tree
![alt text](<Screenshot 2024-05-29 190912.png>)
<p align="justify">Tree adalah kumpulan node yang saling terhubung satu sama lain dalam suatu kesatuan yang membentuk layaknya struktur sebuah pohon. Struktur pohon adalah suatu cara merepresentasikan suatu struktur hirarki (one-to-many) secara grafis yang mirip sebuah pohon, walaupun pohon tersebut hanya tampak sebagai kumpulan node-node dari atas ke bawah. Suatu struktur data yang tidak linier yang menggambarkan hubungan yang hirarkis (one-to-many) dan tidak linier antara elemen-elemennya.</p>

### Istilah Tree
- Predecessor, node yang berada diatas node tertentu
- Successor, node yang berada dibawah node tertentu
- Ancestor, seluruh node yang terletak sebelum node tertentu dan terleteak pada jalur yang sama
- Descendant, seluruh node yang terletak setelah node tertentu dan terletak pada jalur yang sama
- Parent, predecessor satu level di atas suatu node
- Child, successor satu level di bawah suatu node
- Sibling, node-node yang memiliki parent yang sama
- Subtree, suatu node beserta descendantnya
- Size, banyaknya node dalam suatu tree
- Height, banyaknya tingkatan dalam suatu tree
- Root, node khusus yang tidak memiliki predecessor
- Leaf, node-node dalam tree yang tidak memiliki successor
- Degree, banyaknya child daalm suatu node

### Jenis-Jenis Tree
1. Binary Tree</br>
![alt text](<Screenshot 2024-05-29 191124.png>)</br>
Tree dengan syarat bahwa tiap node hanya boleh memiliki maksimal dua sub pohon dan kedua subpohon harus terpisah.
Kelebihan struktur Binary Tree:
- Mudah dalam penyusunan algoritma sorting
- Searching data relatif cepat
- Fleksibel dalam penambahan dan penghapusan data

2. Full Binary Tree</br>
![alt text](<Screenshot 2024-05-29 191159.png>)</br>
Semua node, kecuali leaf pasti memiliki 2 anak dan tiap subpohon memiliki panjang path yang sama.

3. Complete Binary Tree</br>
![alt text](<Screenshot 2024-05-29 191400.png>)</br>
Tree yang mirip dengan full binary tree, tapi tiap subtree boleh memiliki panjang path yang berbeda dan tiap node (kecuali leaf) memiliki 2 anak.

4. Skewed Binary Tree</br>
![alt text](<Screenshot 2024-05-29 191504.png>)</br>
Binary tree yang semua nodenya (kecuali leaf) hanya memiliki satu anak.

### GUIDED 

## 1. Program Graph
```C++
#include <iostream>
#include <iomanip>

using namespace std;
string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};
int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}
};

void tampilGraph() {
    for (int baris=0; baris<7; baris++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom=0; kolom<7; kolom++) {
            if (busur[baris][kolom] != 0) {
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom] << ") ";
            }
        } cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}
```
## OUTPUT 
![alt text](<Screenshot 2024-05-29 191846.png>)

## PENJELASAN 
Program tersebut mendefinisikan dan menampilkan sebuah graf berbasis matriks ketetanggaan untuk tujuh kota di Indonesia (Ciamis, Bandung, Bekasi, Tasikmalaya, Cianjur, Purwokerto, Yogyakarta). Matriks ketetanggaan busur menyimpan jarak antara kota-kota tersebut, dengan nilai nol menunjukkan tidak adanya jalur langsung antara dua kota. Fungsi tampilGraph() digunakan untuk menampilkan graf ini dalam bentuk yang mudah dibaca, dengan mencetak setiap kotabeserta kota-kota yang terhubung langsung dengannya dan jarak antar kota tersebut. Program utama memanggil fungsi tampilGraph() untuk menampilkan informasi graf ini ke layar.

## 2. Program Tree
```c++
#include <iostream>
#include <iomanip>

using namespace std;

struct Pohon
{
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

void init()
{
    root = NULL;
}

bool isEmpty()
{
    return root == NULL;
}

void buatNode(char data)
{
    if (isEmpty())
    {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\n Node " << data << " berhasil dibuat sebagai root."
             << endl;
    }
    else
    {
        cout << "\n Tree sudah ada!" << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\n Node " << node->data << " sudah ada child kiri !" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}

Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\n Node " << node->data << " sudah ada child kanan !" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ingin diganti tidak ada!!" << endl;
        }
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\n Node " << temp << " berhasil diubah menjadi "
                 << data << endl;
        }
    }
}

void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\n Data node : " << node->data << endl;
        }
    }
}

void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\n Data Node : " << node->data << endl;
            cout << " Root : " << root->data << endl;
            if (!node->parent)
                cout << " Parent : (tidak punya parent)" << endl;
            else
                cout << " Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node &&
                node->parent->right == node)
                cout << " Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << " Sibling : " << node->parent->right->data << endl;
            else
                cout << " Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << " Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << " Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << " Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << " Child Kanan : " << node->right->data << endl;
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// inOrder
void inOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\n Node subtree " << node->data << " berhasil dihapus." << endl;
    }
}

void clear()
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
    }
    else
    {
        deleteTree(root);
        cout << "\n Pohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}

// Karakteristik Tree
void characteristic()
{
    cout << "\n Size Tree : " << size() << endl;
    cout << " Height Tree : " << height() << endl;
    cout << " Average Node of Tree : " << size() / height() << endl;
}

int main()
{
    buatNode('A');
    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;
    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);
    update('Z', nodeC);
    update('C', nodeC);
    retrieve(nodeC);
    find(nodeC);
    characteristic();

    cout << "\n PreOrder :" << endl;
    preOrder(root);
    cout << "\n"<< endl;

    cout << " InOrder :" << endl;
    inOrder(root);
    cout << "\n" << endl;

    cout << " PostOrder :" << endl;
    postOrder(root);
    cout << "\n" << endl;
}
```
## OUTPUT
![alt text](<Screenshot 2024-05-29 192402.png>)

## PENJELASAN
Program tersebut mengimplementasikan berbagai operasi pada pohon biner menggunakan struktur data Pohon yang mencakup simpul (node), anak kiri dan kanan (left, right), serta induk (parent). Fungsi utama mencakup pembuatan pohon, penambahan simpul anak kiri dan kanan, pembaruan data simpul, pengambilan dan pencarian data simpul, serta penelusuran pohon dengan metode pre-order, in-order, dan post-order. Selain itu, program ini juga dapat menghapus simpul tertentu atau keseluruhan pohon, serta menghitung ukuran dan tinggi pohon, dan menampilkan karakteristik pohon. Di dalam fungsi main(), pohon dibangun dengan simpul root 'A', kemudian ditambahkan simpul-simpul lainnya, dilakukan pembaruan data, pencarian, serta penelusuran pohon dan ditampilkan hasilnya.

### UNGUDED 

1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.</BR>
Output Program : 
![alt text](<Screenshot 2024-05-29 192734.png>)

## GUIDED 1 
```c++
#include <iostream>
#include <vector> 
#include <iomanip> 

using namespace std;

int main() {
    int Fadhel_171;
    cout << "===== Program Membuat Menghitung Sebuah Jarak Kota Ke Kota Lain =====\n";

    do {
    cout << "\nMasukan Jumalah Simpul : "; cin >> Fadhel_171;

    vector<string> kota(Fadhel_171); 
    cout << "\nMasukan Nama Simpul" << endl;
    for (int i = 0; i < Fadhel_171; ++i) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> kota[i]; 
    }

    vector<vector<int>> kota2(Fadhel_171, vector<int>(Fadhel_171)); 
    cout << "\nJarak Masing - Masing Kota\n";
    for (int i = 0; i < Fadhel_171; ++i) {
        for (int j = 0; j < Fadhel_171; ++j) { 
            cout << kota[i] << " --> " << kota[j] << " = ";
            cin >> kota2[i][j];
        }
    }

    cout << "\n====== Grafik Jarak Kota ======";
    cout << "\n           ";
    for (const auto& city : kota) { 
        cout << setw(10) << city;
    }
    cout << '\n';

    for (int i = 0; i < Fadhel_171; ++i) { 
        cout << setw(10) << kota[i];
        for (int j = 0; j < Fadhel_171; ++j) {
            cout << setw(10) << kota2[i][j]; 
        }
        cout << '\n';
    }
    } while (Fadhel_171 != 0); 
    cout << "Semoga Bisa Membantu";
    return 0;
}
```
## OUTPUT 
![alt text](<Screenshot 2024-05-29 170416.png>)

## PENJELASAN
Program ini memungkinkan pengguna untuk memasukkan sejumlah kota dan menghitung jarak antar kota-kota tersebut dalam bentuk grafik matriks. Pertama, pengguna diminta untuk memasukkan jumlah simpul dan nama-nama kota tersebut. Selanjutnya, program meminta pengguna untuk mengisi jarak antar kota dalam bentuk matriks, di mana jarak dari setiap kota ke kota lainnya dimasukkan. Setelah itu, program menampilkan grafik jarak kota dalam bentuk tabel yang rapi menggunakan manipulasi format dari pustaka. Proses ini diulang sampai pengguna memasukkan jumlah simpul 0. Program ini membantu dalam visualisasi dan penghitungan jarak antar berbagai kota yang diinput oleh pengguna.

2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree
dari user dan berikan fungsi tambahan untuk menampilkan node child dan
descendant dari node yang diinput kan!

## GUIDED 2
```c++
#include <iostream>
#include <iomanip>

using namespace std;

struct Pohon
{
    char data;
    Pohon *kiri, *kanan, *parent;
};

Pohon *root, *baru;

void init() 
{
    root = NULL;
}

bool isEmpty()
{
    return root == NULL;
}

void buatNode(char data) 
{
    if (isEmpty())
    {
        root = new Pohon();
        root->data = data;
        root->kiri = NULL;
        root->kanan = NULL;
        root->parent = NULL;
        cout << "\nNode " << data << " berhasil dibuat sebagai root!" << endl;
    }
    else
    {
        cout << "\nTree sudah ada!" << endl;
    }
}

Pohon *findNode(Pohon *node, char data) 
{
    if (node == NULL) return NULL;
    if (node->data == data) return node;

    Pohon *foundNode = findNode(node->kiri, data);
    if (foundNode == NULL)
        foundNode = findNode(node->kanan, data);

    return foundNode;
}

Pohon *insertkiri(char data, Pohon *node) 
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->kiri != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->kiri = NULL;
            baru->kanan = NULL;
            baru->parent = node;
            node->kiri = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}

Pohon *insertkanan(char data, Pohon *node) 
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->kanan != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->kiri = NULL;
            baru->kanan = NULL;
            baru->parent = node;
            node->kanan = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node) 
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        }
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void find(Pohon *node) 
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\nData Node: " << node->data << endl;
            cout << "Root: " << root->data << endl;
            if (!node->parent)
                cout << "Parent: (tidak punya parent)" << endl;
            else
                cout << "Parent: " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->kiri != node && node->parent->kanan == node)
                cout << "Sibling: " << node->parent->kiri->data << endl;
            else if (node->parent != NULL && node->parent->kanan != node && node->parent->kiri == node)
                cout << "Sibling: " << node->parent->kanan->data << endl;
            else
                cout << "Sibling: (tidak punya sibling)" << endl;
            if (!node->kiri)
                cout << "Child Kiri: (tidak punya child kiri)" << endl;
            else
                cout << "Child Kiri: " << node->kiri->data << endl;
            if (!node->kanan)
                cout << "Child Kanan: (tidak punya child kanan)" << endl;
            else
                cout << "Child Kanan: " << node->kanan->data << endl;
        }
    }
}

void printChild(Pohon *node) 
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else if (!node)
    {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
    }
    else
    {
        if (node->kiri)
        {
            cout << "Child Kiri: " << node->kiri->data << endl;
        }
        else
        {
            cout << "Child Kiri: (tidak ada)" << endl;
        }

        if (node->kanan)
        {
            cout << "Child Kanan: " << node->kanan->data << endl;
        }
        else
        {
            cout << "Child Kanan: (tidak ada)" << endl;
        }
    }
}

void printDescendants(Pohon *node) 
{
    void preOrder(Pohon * node);

    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else if (!node)
    {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
    }
    else
    {
        cout << "Descendants dari node " << node->data << " : ";
        if (node->kiri) preOrder(node->kiri);
        if (node->kanan) preOrder(node->kanan);
        cout << endl;
    }
}


int size(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->kiri) + size(node->kanan);
        }
    }
}


int height(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->kiri);
            int heightKanan = height(node->kanan);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}


void preOrder(Pohon *node)
{
    if (node != NULL)
    {
        cout << " " << node->data << ", ";
        preOrder(node->kiri);
        preOrder(node->kanan);
    }
}



void inOrder(Pohon *node = root)
{
    if (node != NULL)
    {
        inOrder(node->kiri);
        cout << " " << node->data << ", ";
        inOrder(node->kanan);
    }
}


void postOrder(Pohon *node = root)
{
    if (node != NULL)
    {
        postOrder(node->kiri);
        postOrder(node->kanan);
        cout << " " << node->data << ", ";
    }
    cout << endl;
}


void characteristic()
{
    cout << "\n Size Tree : " << size() << endl;
    cout << " Height Tree : " << height() << endl;
    cout << " Average Node of Tree : " << size() / height() << endl;
}

int main()
{
    init();
    char pilihan171, Data171, arah171, ParentData171;
    Pohon *node;

    cout << "\n===== PROGRAM DATA TREE  =====\n";

    do
    {
        cout << "\nMenu: ";
        cout << "\n1. Buat Node Root";
        cout << "\n2. Tambah Child (kiri/kanan)";
        cout << "\n3. Update Node";
        cout << "\n4. Karakteristik";
        cout << "\n5. Temukan Node";
        cout << "\n6. PreOrder Traversal";
        cout << "\n7. InOrder Traversal";
        cout << "\n8. PostOrder Traversal";
        cout << "\n9. Cetak Child";
        cout << "\n0. Cetak Descendants";
        cout << "\nPilih program : "; cin >> pilihan171;

        switch (pilihan171)
        {
        case '1':
            cout << "\n  Input data untuk rootnya: ";
            cin >> Data171;
            buatNode(Data171);
            break;

        case '2': 
            cout << "\nMasukkan data untuk child: ";
            cin >> Data171;
            cout << "\nChild yang diinput berada di posisi (kiri L / kanan R:) ";
            cin >> arah171;
            cout << "\nMasukkan data dari parent node: ";
            cin >> ParentData171;
            node = findNode(root, ParentData171);
            if (node == NULL)
            {
                cout << "\nNode dengan data " << ParentData171 << " tidak ditemukan!" << endl;
            }
            else
            {
                if (arah171 == 'L' || arah171 == 'l')
                {
                    insertkiri(Data171, node);
                }
                else if (arah171 == 'R' || arah171 == 'r')
                {
                    insertkanan(Data171, node);
                }
                else
                {
                    cout << "\nHah! Pilihan tidak valid!" << endl;
                }
            }
            break;

        case '3': 
            cout << "\nMasukkan data baru untuk diupdate: ";
            cin >> Data171;
            cout << "\nMasukkan data dari node yang ingin diupdate: ";
            cin >> ParentData171;
            node = findNode(root, ParentData171);
            if (node == NULL)
            {
                cout << "\nNode dengan data " << ParentData171 << " tidak ditemukan!" << endl;
            }
            else
            {
                update(Data171, node);
            }
            break;

        case '4': 
            cout << "\nKarakteristik dari tree ini:";
            characteristic();
            break;

        case '5': 
            cout << "\nMasukkan data dari node yang ingin dicari: ";
            cin >> ParentData171;
            node = findNode(root, ParentData171);
            if (node == NULL)
            {
                cout << "\nNode dengan data " << ParentData171 << " tidak ditemukan!" << endl;
            }
            else
            {
                find(node);
            }
            break;

        case '6': 
            cout << "\nPreOrder Traversal: ";
            preOrder(root);
            cout << endl;
            break;

        case '7': 
            cout << "\nInOrder Traversal: ";
            inOrder(root);
            cout << endl;
            break;

        case '8': 
            cout << "\nPostOrder Traversal: ";
            postOrder(root);
            cout << endl;
            break;

        case '9': 
            cout << "\nMasukkan data dari node yang ingin melihat child: ";
            cin >> ParentData171;
            node = findNode(root, ParentData171);
            if (node == NULL)
            {
                cout << "\nNode dengan data " << ParentData171 << " tidak ditemukan!" << endl;
            }
            else
            {
                printChild(node);
            }
            break;

        case '0': 
            cout << "\nMasukkan data dari node yang ingin melihat descendants: ";
            cin >> ParentData171;
            node = findNode(root, ParentData171);
            if (node == NULL)
            {
                cout << "\nNode dengan data " << ParentData171 << " tidak ditemukan!" << endl;
            }
            else
            {
                printDescendants(node);
            }
            break;

        default:
            cout << "\nData tidak di temukan" << endl;
            break;
        }
    } while (pilihan171 != '!');
    cout << "\nSelesai Terimakasih" << endl;

    return 0;
}
```
## OUTPUT 
![alt text](<Screenshot 2024-05-29 172005.png>)
![alt text](<Screenshot 2024-05-29 181929.png>)
![alt text](<Screenshot 2024-05-29 182001.png>)
![alt text](<Screenshot 2024-05-29 182019.png>)

## PENJELASAN
Program ini adalah sebuah aplikasi untuk manajemen dan manipulasi struktur data pohon biner. Pengguna dapat membuat sebuah pohon biner dengan melakukan berbagai operasi seperti menambahkan node ke posisi kiri atau kanan, memperbarui data pada node tertentu, menemukan node, dan mencetak child serta descendants dari node yang dipilih. Program juga menyediakan fungsi untuk melihat karakteristik pohon seperti ukuran dan tinggi pohon, serta melakukan traversal pada pohon dengan metode pre-order, in-order, dan post-order. Antarmuka berbasis menu memandu pengguna untuk memilih operasi yang diinginkan, memungkinkan mereka untuk berinteraksi dan memanipulasi struktur pohon dengan mudah. Program terus berjalan sampai pengguna memasukkan karakter untuk keluar dari aplikasi.

## KESIMPULAN 
Jadi kesimpulan dari teori mengenai graph dan tree tersebut adalah bahwa graph dan tree merupakan struktur data yang penting dalam ilmu komputer untuk merepresentasikan hubungan antar objek. Graph terdiri dari simpul dan sisi, dan memiliki berbagai jenis seperti undirected graph, directed graph, weighted graph, dan unweighted graph, yang masing-masing memiliki karakteristik dan aplikasi yang berbeda. Sementara itu, tree adalah struktur data hirarkis yang juga terdiri dari node yang saling terhubung, dengan istilah-istilah khusus seperti root, leaf, parent, dan child. Jenis-jenis tree meliputi binary tree, full binary tree, complete binary tree, dan skewed binary tree, masing-masing dengan aturan dan kegunaan spesifik. Kedua struktur data ini banyak digunakan dalam berbagai aplikasi, termasuk jaringan sosial, pemetaan jalan, dan pemodelan data, serta algoritma penyortiran dan pencarian data.

## REFERENSI
[1] Sedgewick, R., Algorithms in C++ Part 5: Graph Algorithms 3rd Edition. Boston: Addison-Wesley Professional, 2020.
[2] Berry, A., Simonet, G., Computing the Atom Graph of a Graph and the Union Join Graph of a Hypergraph, Vol. 14, Hal. 1-20, 28 November 2021.