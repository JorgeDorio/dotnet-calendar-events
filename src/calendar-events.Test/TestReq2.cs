using Xunit;
using FluentAssertions;
using calendar_events;
using System;

namespace calendar_events.Test;

public class TestReq2
{
    [Theory(DisplayName = "Deve procurar um evento por titulo")]
    [InlineData("Natal", "2022-12-25", "hohoho", 0)]
    public void TestListSearchByTitle(string title, string date, string description,int expected)
    {
			EventList e = new();
			e.GenericList();
			Event _e = new(title, date, description);
			e.Add(_e);
			int index = e.SearchByTitle(title);

			index.Should().Be(expected);
    }

    [Theory(DisplayName = "Deve procurar um evento por data")]
    [InlineData()]
    public void TestListSearchByDate(string title, string date, string description, int expected)
    {
        throw new NotImplementedException();
    }
}
