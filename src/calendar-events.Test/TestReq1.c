using Xunit;
using FluentAssertions;
using calendar_events;
using System;

namespace calendar_events.Test;

public class TestReq1
{
	[Theory(DisplayName = "Deve cadastrar um evento com o construtor completo")]
	[InlineData("Novo evento", "2022-11-20", "Um novo evento")]
	public void TestEventFullConstructor(string title, string date, string description)
	{
		Event e = new Event(title, date, description);
		e.Title.Should().Be(title);
		e.EventDate.Should().Be(DateTime.Parse(date));
		e.Description.Should().Be(description);
	}

	[Theory(DisplayName = "Deve cadastrar um evento com o construtor sem descrição")]
	[InlineData("Novo evento", "2022-11-20")]
	public void TestEventHalfConstructor(string title, string date)
	{
		Event e = new Event(title, date);
		e.Title.Should().Be(title);
		e.EventDate.Should().Be(DateTime.Parse(date));
	}

	[Theory(DisplayName = "Deve atrasar a data de um evento corretamente")]
	[InlineData("Novo evento", "2022-11-20", 2, "2022-11-22")]
	public void TestEventDelayDate(string title, string date, int days, string expected)
	{
		Event instance = new(title, date);
		instance.DelayDate(days);
		var dateResponse = instance.EventDate;
		dateResponse.Should().Be(DateTime.Parse(expected)); 
	}

	[Theory(DisplayName = "Deve imprimir um evento corretamente")]
	[InlineData("Novo evento", "2022-11-20", "Um novo evento", "detailed", "Evento = Novo evento\nDate = 11/20/2022\nDescription = Um novo evento")]    
		public void TestPrintEvent(string title, string date, string description, string format, string expected)
		{
			Event instance = new(title, date, description);
			string response = instance.PrintEvent(format);

			response.Should().Be(expected);	}


}
