#!/usr/bin/python3
"""Lockboxes exercise interview"""


def canUnlockAll(boxes):
    """Determines if all the boxes can be opened"""

    box_status = False
    keys = [0]
    # Guardar todas las llaves, la llave 0 me abrió la caja 0 inicial/
    boxes_index = []  # Tener una  lista del numero de cajas
    boxes_number = len(boxes)

    for i in range(boxes_number):
        # hago una lista con la cantidad de cajas de 0 a n-1
        boxes_index.append(i)

    while len(boxes_index):
        aux = []
        for j in keys:
            if j in boxes_index:
                # si el num de caja es igual al num de llave...
                box_status = True  # se abre la caja
                for key in boxes[j]:
                    if key in boxes_index and key not in keys:
                        # si la llave abre una caja y no está en la lista
                        aux.append(key)  # la agrego a la lista auxiliar
                boxes_index.remove(j)  # y dejo de contar esa caja que se abrió
        keys.extend(aux)  # ir añadiendo las llaves encontradas

        if not box_status:
            return False
        box_status = False
    return True
