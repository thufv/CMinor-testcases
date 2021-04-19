## 测例

这个是 pi 这个 verifying compiler 的公开测例仓库。

所有的公开测例分为 partial correctness 和 total_correctness 两大类，分别放在两个文件夹下面。

每个文件夹里有一个 `answers.json`，是这个文件夹里所有测例的答案，其格式如下

```json
[
    {
        "filename": <filename>,
        "answer": "VERIFIED" or "UNVERIFIED",
        ["timeout": <time> (seconds)] (default as 10s)
    },
    ...
]
```

## 评测脚本

你可以对每个测例单独测试及调试，也可以使用我们提供的评测脚本。

需要 Python >= 3.8

```bash
pip3 install -r requirements.txt
```

在 VC 根目录下，使用

```bash
dotnet build
python3 testcases/test.py
```

