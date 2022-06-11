/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void); //crear lista en memoriaS
int ll_len(LinkedList* this);	//saca el largo, cuantos pasajero dentode la ista
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement); // añade uno al final
int ll_add(LinkedList* this, void* pElement); //para añadir un elemento a la lista
void* ll_get(LinkedList* this, int index); //va a traer, devolver un generico
int ll_set(LinkedList* this, int index,void* pElement);  //modificar, dejas a algo que te cuide el lugar para luego volver, reemplaza
int ll_remove(LinkedList* this,int index);	//remueve el elemento del lugar elegido, sacas
int ll_clear(LinkedList* this);		//limpias la lista, sin eleminar la lista se puede cargar de nuevo datos
int ll_deleteLinkedList(LinkedList* this); //borra el nodo //borra de la memoria la lista, la hace poronga
int ll_indexOf(LinkedList* this, void* pElement); //me devuelve un elemento espefico de la lista
int ll_isEmpty(LinkedList* this);  //si la lista esta vacia o no
int ll_push(LinkedList* this, int index, void* pElement); //añade uno al final, empujando entre  dos nodos //tambien te guarda el lugar, pero se cola un generico, mete un dato entre dos, corre todoo
void* ll_pop(LinkedList* this,int index); //borra el nodo, pero retorna la referencia del elemento //parecido al remove, pero devuelve el elemento ¿, lo saca de la lsita pero lo devuel para mostrar agreagar a otra lista
int ll_contains(LinkedList* this, void* pElement);   //dice si un elemento espefico esta contendido dntro de una lista
int ll_containsAll(LinkedList* this,LinkedList* this2); //todos loes elementos de la lsita 2 contemido em la lista 1
LinkedList* ll_subList(LinkedList* this,int from,int to); //devuelve una nueva lista, desde u hasta, u pedacito
LinkedList* ll_clone(LinkedList* this); //devuelve una lsita clonada una copia de la lsita anterior
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
