Python Interface for Malayalam phonetic analyser
==================================================
.. image:: https://img.shields.io/pypi/v/mlphon.svg
    :target: https://pypi.python.org/pypi/mlphon
    :alt: PyPI Version

This is python interface for the `Malayalam phonetic analyser - mlphon`_.

Installation
------------

Python 3 is required. Using with `venv`_ is recommended

  .. code-block:: console

    $ pip install mlphon

Usage
-----

Grapheme to Phoneme analysis example
------------------------------------

  .. code-block:: python

    from mlphon import G2P
    analyser = G2P()
    analyser.analyse('കേരളം')


Gives

  .. code-block:: python

    [(('<BoS>k<plosive><voiceless><unaspirated><velar>eː<v_sign><EoS><BoS>ɾ<flapped><alveolar>a<schwa><EoS><BoS>ɭ<lateral><retroflex>a<schwa>m<anuswara><EoS>', 0.0),))]


The second item in this result is the weight.
It is not relevant in the current implementation.

Grapheme to Phoneme generation example
--------------------------------------

  .. code-block:: python

    from mlphon import G2P
    generator = G2P()
    generator.generate('<BoS>k<plosive><voiceless><unaspirated><velar>eː<v_sign><EoS><BoS>ɾ<flapped><alveolar>a<schwa><EoS><BoS>ɭ<lateral><retroflex>a<schwa>m<anuswara><EoS>')


Gives

  .. code-block:: python

    (('കേരളം', 0.0),)

The second item in this result is the weight.
It is not relevant in the current implementation.


Grapheme to IPA analysis
--------------------------

  .. code-block:: python

    from mlphon import IPA
    analyser = IPA()
    analyser.analyse("കേരളം")

Gives

  .. code-block:: python

    (('keːɾaɭam<anuswara>', 0.0),)

<anauswara>, <visarga>, <chillu> tags are explicitly shown in the IPA analysis.

Grapheme generation from IPA
----------------------------

  .. code-block:: python

    from mlphon import IPA
    generator = IPA()
    generator.generate('keːɾaɭam<anuswara>')

Gives

  .. code-block:: python

    (('കേരളം', 0.0),)

There can be multiple results in this generation.
Please ignore the irrelevant ones, if any.

Syllablizer
-----------

  .. code-block:: python

    from mlphon import Syllablizer
    syl = Syllablizer()
    syl.syllablize('കേരളം')

Gives


  .. code-block:: python

    ['കേ', 'ര', 'ളം']




Command line interface
----------------------
G2P

  .. code-block:: console

    $ mlg2p --help
      usage: mlg2p [-h] [-i INFILE] [-o OUTFILE] [-a] [-g] [-v]
      optional arguments:
      -h, --help            show this help message and exit
      -i INFILE, --input INFILE
                        source of analysis data
      -o OUTFILE, --output OUTFILE
                        target of generated strings
      -a, --analyse         Analyse the input file strings
      -g, --generate        Generate the input file strings
      -v, --verbose         print verbosely while processing

IPA

  .. code-block:: console

    $ mlipa --help
      usage: mlipa [-h] [-i INFILE] [-o OUTFILE] [-a] [-g] [-v]
      optional arguments:
      -h, --help            show this help message and exit
      -i INFILE, --input INFILE
                        source of analysis data
      -o OUTFILE, --output OUTFILE
                        target of generated strings
      -a, --analyse         Analyse the input file strings
      -g, --generate        Generate the input file strings
      -v, --verbose         print verbosely while processing

Syllablizer


  .. code-block:: console

    $ mlsyllablize --help
      usage: mlsyllablize [-h] [-i INFILE] [-o OUTFILE]
      optional arguments:
      -h, --help            show this help message and exit
      -i INFILE, --input INFILE
                        source of analysis data
      -o OUTFILE, --output OUTFILE
                        target of generated strings

Tag Parse Functions
-------------------

The analysis function of G2P returns the output with tags in angle brackets.The following functions parses and separates tags, syllables and phoneme sequences.


getPhonemelist()
---------------------

  .. code-block:: python

    from mlphon import G2P, getPhonemelist
    g2p = G2P()
    analysis = g2p.analyse('കേരളം')
    for item in analysis:
      getPhonemelist(item[0])

Gives


  .. code-block:: python
    
      'k eː ɾ a ɭ a m'



getPhonemetaglist()
-------------------

  .. code-block:: python

    from mlphon import G2P, getPhonemetaglist
    g2p = G2P()
    analysis = g2p.analyse('കേരളം')
    for item in analysis:
      getPhonemetaglist(item[0])

Gives

  .. code-block:: python
  
      [{'phonemes': [{'ipa': 'k', 'tags': ['plosive', 'voiceless', 'unaspirated', 'velar']}, {'ipa': 'eː', 'tags': ['v_sign']}]}, {'phonemes': [{'ipa': 'ɾ', 'tags': ['flapped', 'alveolar']}, {'ipa': 'a', 'tags': ['schwa']}]}, {'phonemes': [{'ipa': 'ɭ', 'tags': ['lateral', 'retroflex']}, {'ipa': 'a', 'tags': ['schwa']}, {'ipa': 'm', 'tags': ['anuswara']}]}]

getSyllablelist()
------------------


  .. code-block:: python

    from mlphon import G2P, getSyllablelist
    g2p = G2P()
    analysis = g2p.analyse('കേരളം')
    for item in analysis:
      getSyllablelist(item[0])

It gives the syllable separated output as:

  .. code-block:: python

    ['k<plosive><voiceless><unaspirated><velar>eː<v_sign>', 'ɾ<flapped><alveolar>a<schwa>', 'ɭ<lateral><retroflex>a<schwa>m<anuswara>']



.. _`Malayalam Phonetic Analyser - mlphon`: https://gitlab.com/smc/mlphon
.. _`venv`: https://docs.python.org/3/library/venv.html
