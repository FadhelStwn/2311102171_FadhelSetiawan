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