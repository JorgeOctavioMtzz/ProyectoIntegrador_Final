#include<iostream>
#include <string>
#include "Comprador.h"
#include "Vendedor.h"
using namespace std;
void IDatosComprador(Comprador ArrPersona[], int &numCompradores)
{
    numCompradores = 0;
    string pais, estado, ciudad, colonia, calle, noTarjeta, USername;
    int CVV, mes, año, numCasa, codPostal;
    double saldo;
    cout << "¿Cuantos compradores quieres registrar? (Max. 20) "; cin >> numCompradores;
    for (int cont=0; cont < numCompradores ; cont++)
    {
        cout << "Nombre del comprador: "; cin >> USername;
        cout << "Direccion a la que se enviará su producto: " << endl;
        cout << "Pais: "; cin >> pais;
        cout << "Estado: "; cin >> estado;
        cout << "Ciudad: "; cin >> ciudad; 
        cout << "Colonia: "; cin >> colonia; 
        cout << "Calle: "; cin >> calle;
        cout << " " << endl;
        cout << "Numero de casa: "; cin >> numCasa; 
        cout << "Codigo Postal: "; cin >> codPostal; 
        Direccion Ndireccion(pais, estado, ciudad, colonia, calle, numCasa, codPostal);
        cout << "\nIngrese los 16 dígitos de su tarjeta de credito: "; cin >> noTarjeta; 
        cout << "Ingrese su CVV: "; cin >> CVV;
        cout << "Ingrese su Saldo: "; cin >> saldo; 
        cout << "Ingrese el mes de expiración: "; cin >> mes; 
        cout << "Ingrese el año de expiración: "; cin >> año; 
        CtaBanc CtaIngresada(noTarjeta, CVV, saldo, mes, año);
        if (noTarjeta.size() == 16 && codPostal <= 99999 && CVV <= 999 && mes <= 12 && año >= 2020 )
        {
            ArrPersona[cont].setNombre(USername);
            ArrPersona[cont].setDireccion(Ndireccion);
            ArrPersona[cont].setCtaBanc(CtaIngresada);
        }
        else
        {
            cout << "\nError Datos No Válidos, Comprador no registrado...\n";
            Direccion DireccionDef;
            CtaBanc BancDef;
            ArrPersona[cont].setNombre("NoRegistrado");
            ArrPersona[cont].setDireccion(DireccionDef);
            ArrPersona[cont].setCtaBanc(BancDef);
        }
        
    }
}   

void IDatosVendedor(Vendedor ArrVendedor[], int &numVendedores)
{
    numVendedores=0;
    string pais, estado, ciudad, colonia, calle, noTarjeta, Prod1, Prod2, Prod3,USername;
    double Prec1, Prec2, Prec3, saldo;
    int numCasa, codPostal;
    cout << "¿Cuantos Vendedores quieres registrar? (Max. 20) "; cin >> numVendedores;

    for (int cont=0; cont < numVendedores ; cont++)
    {
        cout << "Nombre del vendedor: "; cin >> USername;
        cout << "Direccion desde la que se enviará su producto: " << endl;
        cout << "Pais: "; cin >> pais;
        cout << "Estado: "; cin >> estado;
        cout << "Ciudad: "; cin >> ciudad; 
        cout << "Colonia: "; cin >> colonia; 
        cout << "Calle: "; cin >> calle;
        cout << "\n" << endl;
        cout << "Numero de casa: "; cin >> numCasa; 
        cout << "Codigo Postal: "; cin >> codPostal; 
        Direcciontwo Ndireccion(pais, estado, ciudad, colonia, calle, numCasa, codPostal);
        cout << "Ingrese los 16 dígitos de su tarjeta de credito: "; cin >> noTarjeta; cout << endl;
        cout << "Ingrese su Saldo: "; cin >> saldo; cout << endl;
        cout << "\n" << endl;
        CtaBanc CtaIngresada;
        CtaIngresada.setNoTarjeta(noTarjeta);
        CtaIngresada.setSaldo(saldo);
        if ( noTarjeta.size() == 16 && codPostal <= 99999 && saldo >= 0)
        {
            ArrVendedor[cont].setNombre(USername);
            ArrVendedor[cont].setDireccion(Ndireccion);
            ArrVendedor[cont].setCtaBanc(CtaIngresada);
            ArrVendedor[cont].setDireccion(Ndireccion);
            ArrVendedor[cont].setCtaBanc(CtaIngresada);
            cout << "Nombre de tu producto 1: "; cin >> Prod1;
            cout << "Ingresa el precio de tu producto 1: "; cin >> Prec1;
            cout << "Nombre de tu producto 2: "; cin >> Prod2;
            cout << "Ingresa el precio de tu producto 2: "; cin >> Prec2;
            cout << "Nombre de tu producto 3: "; cin >> Prod3;
            cout << "Ingresa el precio de tu producto 3: "; cin >> Prec3;
            ArrVendedor[cont].setNombre(USername);
            ArrVendedor[cont].setProducto1(Prod1);
            ArrVendedor[cont].setPrecio1(Prec1);
            ArrVendedor[cont].setProducto2(Prod2);
            ArrVendedor[cont].setPrecio2(Prec2);
            ArrVendedor[cont].setProducto3(Prod3);
            ArrVendedor[cont].setPrecio3(Prec3);
        }
        else
        {
            cout << "\nError Datos No Válidos, Vendedor no registrado...\n";
            Direcciontwo DireccionDef;
            CtaBanc BancDef;
            ArrVendedor[cont].setNombre("NoRegistrado");
            ArrVendedor[cont].setDireccion(DireccionDef);
            ArrVendedor[cont].setCtaBanc(BancDef);
        }
    }
}   

void Login(Comprador arrComp[], int noComp, Comprador &Compsel, bool &Val)
{   
    string User;
    Comprador CompradorDFT;
    cout << "¿Quien Esta Comprando? "; cin >> User;
    for (int cont=0; cont < noComp; cont++)
    {
        if (arrComp[cont].getName() == User)
        {
            Compsel = arrComp[cont];
            Val = true;
        }
        else
        {
            cout << "Error 404: Tu nombre no coincide con nuestros Datos, favor de Registrarse...";
            Compsel = CompradorDFT;
            Val = false;
        }
    }
}

void SeleccionV(Vendedor arrVend[], int noVend, Vendedor VendeSel)
{
    string VendedorS;
    Vendedor VendedorDft;
    cout << "Selecciona el Vendor "; cin >> VendedorS;
    for (int cont=0; cont < noVend; cont++)
    {
        if (arrVend[cont].getName() == VendedorS)
        {
            VendeSel =  arrVend[cont];
        }
        else
        {
            cout << "Error 404: El vendedor seleccionado no existe";
            VendeSel = VendedorDft;
        }
    }
}

void SeleccionP(double &Valor, string &NProducto, int noVend, Vendedor arrVend[])
{
    string ProductoS;
    cout << "Selecciona tu Producto "; cin >> ProductoS;
    for (int cont=0; cont < noVend; cont++)
    {
        if (arrVend[cont].getProducto1() == ProductoS)
        {
            NProducto = arrVend[cont].getProducto1();
            Valor = arrVend[cont].getPrecio1();
        }
        else if (arrVend[cont].getProducto2() == ProductoS)
        {
            NProducto = arrVend[cont].getProducto2();
            Valor = arrVend[cont].getPrecio2();
        }
        else if (arrVend[cont].getProducto3() == ProductoS)
        {
            NProducto = arrVend[cont].getProducto3();
            Valor = arrVend[cont].getPrecio3();
        }
        
    }
}

double CalculoPrecio(Vendedor V, Comprador C, double VaP)
{
    double PrecioF;
    if (V.getDireccion().getPais() == C.getDireccion().getPais())
    {
        PrecioF = (VaP*0.16) + VaP;
        cout << "Envio Nacional ";
    }
    else
    {
        PrecioF = (VaP*0.16) + VaP + 100;
        cout << "Envio Internacional ";
    }
    return PrecioF;
}

int main()
{
    Comprador arrCompradores[20];
    Vendedor arrVendedores[20];
    Comprador CompradorA;
    Vendedor VendedorA;
    double ValoraPagar, ValorTotal;
    string ProductoaPagar, Sel;
    int nComp=0, nVend=0;
    char opcion;
    do{
        cout << endl;
        cout << "a) Registrar compradores " << endl;
        cout << "b) Consultar datos compradores " << endl;
        cout << "c) Registrar Vendedores " << endl;
        cout << "d) Consultar Productos " << endl;
        cout << "e) Realizar Compra " << endl;
        cout << "X) Exit " << endl;
        cout << " opcion -> "; cin >> opcion;
        switch (opcion)
        {
        case 'a':
            IDatosComprador(arrCompradores, nComp);
            break;
        case 'b':
            if (nComp == 0)
            {
                cout << "\nError, no hay Compradores Registrados...\n";
            }
            else
            {
                for (int cont=0; cont < nComp; cont++)
                {
                    arrCompradores[cont].print(); cout << "\n";
                    arrCompradores[cont].getDireccion().print(); cout << "\n";
                    cout << "\n";
                }
            }
            break;
        case 'c':
            IDatosVendedor( arrVendedores, nVend);

            break;
        case 'd':
            if (nVend == 0)
            {
                cout << "\nError no hay ningun Producto registrado...\n";
            }            
            else
            {
                for (int cont=0; cont < nVend; cont++)
                {
                    arrVendedores[cont].print(); cout << "\n";
                    arrVendedores[cont].getDireccion().print(); cout << "\n";
                    cout << "\n";
                }


                for (int cont=0; cont < nVend; cont++)
                {
                    arrVendedores[cont].PrintProd(); cout << "\n";
                }
            }
            break;
        case 'e':
            if (nComp == 0 || nVend == 0)
            {
                cout << "\nError no hay ningun Comprador/Vendedor Registrado...\n";
            }
            else
            {
                bool Vali;
                for (int cont=0; cont < nComp; cont++)
                {
                    cout << arrCompradores[cont].getName();
                }
                cout << endl;
                Login(arrCompradores, nComp, CompradorA, Vali);
                if (Vali == true)
                {
                    for (int cont=0; cont < nVend; cont++)
                    {
                        cout << arrVendedores[cont].getName();
                    }
                    cout << endl;
                    SeleccionV(arrVendedores, nVend, VendedorA);

                    for (int cont=0; cont < (nVend); cont++)
                    {
                        cout << "Vendedor " << cont;
                        arrVendedores[cont].PrintProd();
                        cout << "\n";
                    }
                    SeleccionP(ValoraPagar, ProductoaPagar, nVend, arrVendedores);
                    cout << endl;
                    ValorTotal = CalculoPrecio(VendedorA, CompradorA, ValoraPagar);
                    cout << "¿Quieres Proseguir con la compra?" << endl;
                    cout << "Tu Compra:" << ProductoaPagar << "          $" << ValoraPagar <<endl;
                    cout << "Si/No"; cin >> Sel;
                    if (Sel == "Si" && CompradorA.getDtaBanc().getSaldo() >= ValoraPagar)
                    {
                        double SaldoFC, SaldoFV;
                        cout << "El producto " << ProductoaPagar << " sera enviado a " << CompradorA.getName() << endl;
                        cout << "A la dirección:" << endl;
                        CompradorA.getDireccion().print();
                        SaldoFC = (CompradorA.getDtaBanc().getSaldo() - ValoraPagar);
                        SaldoFV = (VendedorA.getDtaBanc().getSaldo() + ValoraPagar);
                        CompradorA.getDtaBanc().setSaldo(SaldoFC);
                        VendedorA.getDtaBanc().setSaldo(SaldoFV);
                    }
                    
                    else if (Sel == "Si" && CompradorA.getDtaBanc().getSaldo() < ValoraPagar)
                    {
                        cout << "Compra Cancelada, tu saldo es insuficiente...";
                    }
                    else
                    {
                        cout << "Compra Cancelada...";
                    }
                }
            }
            break;
        }

    }while (opcion != 'X');
    
    return 0;
}
