import importlib.util
import os
from typing import List, Optional

from helpers import ListNode

PROJECT_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def load_solution(problem_name, class_name="Solution"):
    folder = os.path.join(PROJECT_ROOT, problem_name)
    py_file = os.path.join(folder, f"{problem_name}.py")

    spec = importlib.util.spec_from_file_location(problem_name, py_file)
    module = importlib.util.module_from_spec(spec)

    module.List = List
    module.Optional = Optional
    module.ListNode = ListNode

    spec.loader.exec_module(module)
    return getattr(module, class_name)
