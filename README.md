# llm_playground
An LLM Engineering playground

# Basics

1. Install Github
2. Install Python 3.11+
3. Install Conda (https://anaconda.com)

# Env with conda

Build the environment:
```bash
conda env create -f environment.yml
```

Activate the environment:
```bash
conda activate llms
```

To deactivate the environment:
```bash
conda deactivate
```

# Alternatively with python

Create a virtualenv:
```bash
python -m virtualenv env
```

Activate the environment:
```bash
source env/bin/activate # On Windows use env/Scripts/activate
```

To deactivate the environment:
```bash
deactivate
```

# Jupyter Lab

Launch the jupyter notebook lab:
```bash
jupyter lab
```

If you need to install extra packages make sure to add it to the environment and update it:
```bash
conda env update --file environment.yml --prune
```

# Thanks

Udemy course: https://www.udemy.com/course/llm-engineering-master-ai-and-large-language-models/
