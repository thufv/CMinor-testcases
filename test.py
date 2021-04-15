#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# 使用方式：./test.py
# 这个脚本应该在 piVC-thu 这个项目的根目录下运行

import os
import subprocess
import json
from prettytable import PrettyTable


def run_and_check(filepath: str, answer: str) -> bool:
    assert filepath.endswith(".pi")
    assert os.path.exists(filepath)
    cp = subprocess.run(["dotnet", "run", "--no-build", "--",
                         "--source", filepath], check=True, capture_output=True)
    return cp.stdout.decode("utf-8").strip().endswith("VERIFIED")


def test():
    # 先编译，[抛弃，交给CI的前一个阶段]
    # subprocess.run(["dotnet", "build"], check=True) 

    # 初始化
    score = 0
    table = PrettyTable()
    table.field_names = ["Category",
                         "Consistent cases", "Total cases", "Score"]

    total_score = 0
    with open(os.path.join("testcases", "answers.json"), "r") as f:
        categories = json.load(f)
        for category in categories:
            sum = 0
            for filepath in category["verified_cases"]:
                if run_and_check(os.path.join("testcases", filepath), "VERIFIED"):
                    sum += 1
            for filepath in category["unverified_cases"]:
                if run_and_check(os.path.join("testcases", filepath), "UNVERIFIED"):
                    sum += 1

            # 计算分数
            total = len(category["verified_cases"]) + \
                len(category["unverified_cases"])
            score += sum / total * category["score"]
            total_score += category["score"]

            # 放到表格里
            table.add_row([category["name"], sum, total,
                           "{:.1f} ({})".format(score, category["score"])])

    # 把最终的结果也放进表里
    table.add_row(["TOTAL", "", "", score])

    # 把表格打印出来
    print(table)

    print('Your total score coverage is: {:.1f} %'.format(score/total_score * 100))

    return score


if __name__ == "__main__":
    test()
