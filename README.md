NILAN Ventilation Modbus Communication
=====================================

.. seo::
    :description: Instructions for setting up NILAN Modbus.
    :image: nilan.png
    :keywords: NILAN Ventilation

.. note::

    This page is incomplete and could some work. If you want to contribute, please read the
    :doc:`contributing guide </guides/contributing>`. This page is missing:

      - An image for the front page.
      - Images/screenshots/example configs of this device being used in action.

The sensor can be connected in various configurations - please see the `manufacturer's website <https://en.nilan.dk/en-gb/frontpage/download>`__
for more information.

.. warning::

    This is only working for NILAN Light models.

The communication with this integration is done over a :ref:`UART bus <uart>`.
You must therefore have a ``uart:`` entry in your configuration with both the TX and RX pins set
to some pins on your board and the baud rate set to 9600.

.. code-block:: yaml

    # Example configuration entry
    uart:
      rx_pin: D1
      tx_pin: D2
      baud_rate: 9600

    sensor:
      - platform: nilan  //testnilan
        current:
          name: "PZEM-004T V3 Current"
        voltage:
          name: "PZEM-004T V3 Voltage"
        energy:
          name: "PZEM-004T V3 Energy"
        power:
          name: "PZEM-004T V3 Power"
        frequency:
          name: "PZEM-004T V3 Frequency"
        power_factor:
          name: "PZEM-004T V3 Power Factor"
        update_interval: 60s

Configuration variables:
------------------------


- **update_interval** (*Optional*, :ref:`config-time`): The interval to check the
  sensor. Defaults to ``60s``.
- **address** (*Optional*, int): The address of the sensor if multiple sensors are attached to
  the same UART bus. You will need to set the address of each device manually. Defaults to ``1``.

