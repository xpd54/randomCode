from typing import Dict


def get_data_formate(name, message, value) -> Dict:
    holding = {}
    holding["name"] = name
    holding["message"] = message
    holding["value"] = value
    return holding


print(get_data_formate("ravi", "Hello", 23))
